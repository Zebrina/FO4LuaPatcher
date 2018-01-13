#include "LuaScriptProcessor.h"

#include <fstream>
#include <sstream>

#include <Windows.h>

#include "f4se/GameAPI.h"
#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameTypes.h"

#include <luacppinterface.h>

#include "LuaForm.h"
#include "LuaGame.h"
#include "LuaMiscObject.h"

using namespace std;

STATIC_ASSERT(sizeof(void*) == sizeof(UInt64));

#define LUA_DEBUG_PRINT(fmt, ...) _MESSAGE(fmt, __VA_ARGS__);Console_Print(fmt, __VA_ARGS__)

void LuaPrint(const char* str) {
	Console_Print("Lua: %s", str);
}

bool RunLuaFile(Lua* lua, const char* file) {
	ifstream fs(file);
	if (fs.good()) {
		string script;

		fs.seekg(0, ios::end);
		script.reserve(fs.tellg());
		fs.seekg(0, ios::beg);

		script.assign((istreambuf_iterator<char>(fs)), istreambuf_iterator<char>());
		string result = lua->RunScript(script);
		if (result != "No errors") {
			LUA_DEBUG_PRINT("Lua %s", result.c_str());
			return false;
		}

		return true;
	}

	LUA_DEBUG_PRINT("Lua Error: Failed to open file %s", file);
	return false;
}
bool RunLuaScript(Lua* lua, const char* script) {
	string result = lua->RunScript(script);
	if (result != "No errors") {
		LUA_DEBUG_PRINT("Lua %s", result.c_str());
		return false;
	}

	return true;
}

template <class T>
void ForEachFileInFolder(const char* folder, const char* file, T func) {
	string folderStr = folder;
	WIN32_FIND_DATA findFileData;
	HANDLE hFile = FindFirstFile((folderStr + file).c_str(), &findFileData);
	if (hFile != INVALID_HANDLE_VALUE) {
		do {
			func((folderStr + findFileData.cFileName).c_str());
		} while (FindNextFile(hFile, &findFileData) != 0);
	}
	FindClose(hFile);
}

template <class T>
void ForEachFormInvokeCallbacks(Lua* lua, LuaTable* global, LuaTable* callbacks, T& list) {
	for (SInt32 i = 0; i < list.count; ++i) {
		try {
			TESForm* form = static_cast<TESForm*>(list[i]);
			callbacks->ForAllIntegerKeys([lua, global, form, callbacks](SInt64 index, LuaType::Value value) {
				if (value == LuaType::Value::function) {
					global->Set("InvokeCallback", callbacks->Get<LuaFunction<void(uint32_t)>>((int)index));

					stringstream script;
					script << "InvokeCallback(" << form->formID << ")";

					RunLuaScript(lua, script.str().c_str());
				}
			});
		}
		catch (const exception& e) {
			Console_Print("Lua Error: %s", e.what());
		}
	}
}

void ProcessLuaScripts() {
	LUA_DEBUG_PRINT("Lua Patcher started.");

	Lua lua;
	LuaTable global = lua.GetGlobalEnvironment();

	lua.LoadStandardLibraries();
	_MESSAGE("Loaded standard libraries.");

	// Redirect print to in-game console.
	global.Set("print", lua.CreateFunction<void(const char*)>(LuaPrint));
	_MESSAGE("Registered print.");

	// FormType constants.
	global.Set("CMPO", (UInt8)FormType::kFormType_CMPO);
	global.Set("GLOB", (UInt8)FormType::kFormType_GLOB);
	global.Set("RACE", (UInt8)FormType::kFormType_RACE);
	global.Set("MGEF", (UInt8)FormType::kFormType_MGEF);
	global.Set("ENCH", (UInt8)FormType::kFormType_ENCH);
	global.Set("SPEL", (UInt8)FormType::kFormType_SPEL);
	global.Set("ARMO", (UInt8)FormType::kFormType_ARMO);
	global.Set("CONT", (UInt8)FormType::kFormType_CONT);
	global.Set("DOOR", (UInt8)FormType::kFormType_DOOR);
	global.Set("INGR", (UInt8)FormType::kFormType_INGR);
	global.Set("LIGH", (UInt8)FormType::kFormType_LIGH);
	global.Set("MISC", (UInt8)FormType::kFormType_MISC);
	global.Set("STAT", (UInt8)FormType::kFormType_STAT);
	global.Set("FLOR", (UInt8)FormType::kFormType_FLOR);
	global.Set("FURN", (UInt8)FormType::kFormType_FURN);
	global.Set("WEAP", (UInt8)FormType::kFormType_WEAP);
	global.Set("AMMO", (UInt8)FormType::kFormType_AMMO);
	global.Set("NPC_", (UInt8)FormType::kFormType_NPC_);
	global.Set("LVLN", (UInt8)FormType::kFormType_LVLN);
	global.Set("KEYM", (UInt8)FormType::kFormType_KEYM);
	global.Set("ALCH", (UInt8)FormType::kFormType_ALCH);
	global.Set("NOTE", (UInt8)FormType::kFormType_NOTE);
	global.Set("PROJ", (UInt8)FormType::kFormType_PROJ);
	global.Set("TERM", (UInt8)FormType::kFormType_TERM);
	global.Set("LVLI", (UInt8)FormType::kFormType_LVLI);
	global.Set("QUST", (UInt8)FormType::kFormType_QUST);
	global.Set("FLST", (UInt8)FormType::kFormType_FLST);
	global.Set("PERK", (UInt8)FormType::kFormType_PERK);
	global.Set("MESG", (UInt8)FormType::kFormType_MESG);
	global.Set("OTFT", (UInt8)FormType::kFormType_OTFT);
	global.Set("COBJ", (UInt8)FormType::kFormType_COBJ);
	global.Set("OMOD", (UInt8)FormType::kFormType_OMOD);
	global.Set("INNR", (UInt8)FormType::kFormType_INNR);
	_MESSAGE("Registered FormType constants.");

	LuaForm::RegisterFunctions(&lua, &global);
	_MESSAGE("Registered Form functions.");
	LuaGame::RegisterFunctions(&lua, &global);
	_MESSAGE("Registered Game functions.");
	LuaMiscObject::RegisterFunctions(&lua, &global);
	_MESSAGE("Registered MiscObject functions.");

	ForEachFileInFolder("Data\\F4SE\\Plugins\\LuaPatcher\\Core\\", "*.lua", [&lua](const char* file) {
		RunLuaFile(&lua, file);
	});
	_MESSAGE("Core loaded.");
	ForEachFileInFolder("Data\\F4SE\\Plugins\\LuaPatcher\\Scripts\\", "*.lua", [&lua](const char* file) {
		RunLuaFile(&lua, file);
	});
	_MESSAGE("Scripts loaded.");

	LuaTable patcher = global.Get<LuaTable>("patcher");
	LuaTable callbacks = patcher.Get<LuaTable>("callbacks");

	DataHandler* dataHandler = *g_dataHandler;

	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCMPO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrGLOB);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRACE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMGEF);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrENCH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSPEL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrARMO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCONT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDOOR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrINGR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLIGH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMISC);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSTAT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFLOR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFURN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWEAP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAMMO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNPC_);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLVLN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrKEYM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrALCH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNOTE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPROJ);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTERM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLVLI);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrQUST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFLST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPERK);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMESG);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrOTFT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCOBJ);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrOMOD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrINNR);

	LuaForm::ClearCaches();

	LUA_DEBUG_PRINT("Lua Patcher finished.");
}