#include "LuaScriptProcessor.h"

#include <fstream>
#include <sstream>

#include <Windows.h>

#include "f4se/GameAPI.h"
#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameTypes.h"

#include <luacppinterface.h>

#include "LuaActivator.h"
#include "LuaActorBase.h"
#include "LuaActorValue.h"
#include "LuaAmmo.h"
#include "LuaArmor.h"
#include "LuaBook.h"
#include "LuaClass.h"
#include "LuaCombatStyle.h"
#include "LuaComponent.h"
#include "LuaConstructibleObject.h"
#include "LuaContainer.h"
#include "LuaDoor.h"
#include "LuaEnchantment.h"
#include "LuaEncounterZone.h"
#include "LuaEquipSlot.h"
#include "LuaExplosion.h"
#include "LuaFaction.h"
#include "LuaFlora.h"
#include "LuaForm.h"
#include "LuaFurniture.h"
#include "LuaGame.h"
#include "LuaGlobalVariable.h"
#include "LuaHolotape.h"
#include "LuaIngredient.h"
#include "LuaKey.h"
#include "LuaKeyword.h"
#include "LuaLeveledActor.h"
#include "LuaLeveledItem.h"
#include "LuaLeveledSpell.h"
#include "LuaLocation.h"
#include "LuaMagicEffect.h"
#include "LuaMessage.h"
#include "LuaMiscObject.h"
#include "LuaMovableStatic.h"
#include "LuaObjectMod.h"
#include "LuaOutfit.h"
#include "LuaPackage.h"
#include "LuaPerk.h"
#include "LuaPotion.h"
#include "LuaQuest.h"
#include "LuaRace.h"
#include "LuaSpell.h"
#include "LuaSoulGem.h"
#include "LuaStatic.h"
#include "LuaTalkingActivator.h"
#include "LuaTerminal.h"
#include "LuaWeapon.h"
#include "LuaWeather.h"

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
	global.Set("KYWD", (uint8_t)FormType::kFormType_KYWD);
	global.Set("LCRT", (uint8_t)FormType::kFormType_LCRT);
	global.Set("AACT", (uint8_t)FormType::kFormType_AACT);
	global.Set("TRNS", (uint8_t)FormType::kFormType_TRNS);
	global.Set("CMPO", (uint8_t)FormType::kFormType_CMPO);
	global.Set("TXST", (uint8_t)FormType::kFormType_TXST);
	global.Set("MICN", (uint8_t)FormType::kFormType_MICN);
	global.Set("GLOB", (uint8_t)FormType::kFormType_GLOB);
	global.Set("DMGT", (uint8_t)FormType::kFormType_DMGT);
	global.Set("CLAS", (uint8_t)FormType::kFormType_CLAS);
	global.Set("FACT", (uint8_t)FormType::kFormType_FACT);
	global.Set("HDPT", (uint8_t)FormType::kFormType_HDPT);
	global.Set("EYES", (uint8_t)FormType::kFormType_EYES);
	global.Set("RACE", (uint8_t)FormType::kFormType_RACE);
	global.Set("SOUN", (uint8_t)FormType::kFormType_SOUN);
	global.Set("ASPC", (uint8_t)FormType::kFormType_ASPC);
	global.Set("SKIL", (uint8_t)FormType::kFormType_SKIL);
	global.Set("MGEF", (uint8_t)FormType::kFormType_MGEF);
	global.Set("SCPT", (uint8_t)FormType::kFormType_SCPT);
	global.Set("LTEX", (uint8_t)FormType::kFormType_LTEX);
	global.Set("ENCH", (uint8_t)FormType::kFormType_ENCH);
	global.Set("SPEL", (uint8_t)FormType::kFormType_SPEL);
	global.Set("SCRL", (uint8_t)FormType::kFormType_SCRL);
	global.Set("ACTI", (uint8_t)FormType::kFormType_ACTI);
	global.Set("TACT", (uint8_t)FormType::kFormType_TACT);
	global.Set("ARMO", (uint8_t)FormType::kFormType_ARMO);
	global.Set("BOOK", (uint8_t)FormType::kFormType_BOOK);
	global.Set("CONT", (uint8_t)FormType::kFormType_CONT);
	global.Set("DOOR", (uint8_t)FormType::kFormType_DOOR);
	global.Set("INGR", (uint8_t)FormType::kFormType_INGR);
	global.Set("LIGH", (uint8_t)FormType::kFormType_LIGH);
	global.Set("MISC", (uint8_t)FormType::kFormType_MISC);
	global.Set("STAT", (uint8_t)FormType::kFormType_STAT);
	global.Set("SCOL", (uint8_t)FormType::kFormType_SCOL);
	global.Set("MSTT", (uint8_t)FormType::kFormType_MSTT);
	global.Set("GRAS", (uint8_t)FormType::kFormType_GRAS);
	global.Set("TREE", (uint8_t)FormType::kFormType_TREE);
	global.Set("FLOR", (uint8_t)FormType::kFormType_FLOR);
	global.Set("FURN", (uint8_t)FormType::kFormType_FURN);
	global.Set("WEAP", (uint8_t)FormType::kFormType_WEAP);
	global.Set("AMMO", (uint8_t)FormType::kFormType_AMMO);
	global.Set("NPC_", (uint8_t)FormType::kFormType_NPC_);
	global.Set("LVLN", (uint8_t)FormType::kFormType_LVLN);
	global.Set("KEYM", (uint8_t)FormType::kFormType_KEYM);
	global.Set("ALCH", (uint8_t)FormType::kFormType_ALCH);
	global.Set("IDLM", (uint8_t)FormType::kFormType_IDLM);
	global.Set("NOTE", (uint8_t)FormType::kFormType_NOTE);
	global.Set("PROJ", (uint8_t)FormType::kFormType_PROJ);
	global.Set("HAZD", (uint8_t)FormType::kFormType_HAZD);
	global.Set("BNDS", (uint8_t)FormType::kFormType_BNDS);
	global.Set("SLGM", (uint8_t)FormType::kFormType_SLGM);
	global.Set("TERM", (uint8_t)FormType::kFormType_TERM);
	global.Set("LVLI", (uint8_t)FormType::kFormType_LVLI);
	global.Set("WTHR", (uint8_t)FormType::kFormType_WTHR);
	global.Set("CLMT", (uint8_t)FormType::kFormType_CLMT);
	global.Set("SPGD", (uint8_t)FormType::kFormType_SPGD);
	global.Set("RFCT", (uint8_t)FormType::kFormType_RFCT);
	global.Set("REGN", (uint8_t)FormType::kFormType_REGN);
	global.Set("NAVI", (uint8_t)FormType::kFormType_NAVI);
	global.Set("CELL", (uint8_t)FormType::kFormType_CELL);
	global.Set("REFR", (uint8_t)FormType::kFormType_REFR);
	global.Set("ACHR", (uint8_t)FormType::kFormType_ACHR);
	global.Set("PMIS", (uint8_t)FormType::kFormType_PMIS);
	global.Set("PARW", (uint8_t)FormType::kFormType_PARW);
	global.Set("PGRE", (uint8_t)FormType::kFormType_PGRE);
	global.Set("PBEA", (uint8_t)FormType::kFormType_PBEA);
	global.Set("PFLA", (uint8_t)FormType::kFormType_PFLA);
	global.Set("PCON", (uint8_t)FormType::kFormType_PCON);
	global.Set("PBAR", (uint8_t)FormType::kFormType_PBAR);
	global.Set("PHZD", (uint8_t)FormType::kFormType_PHZD);
	global.Set("WRLD", (uint8_t)FormType::kFormType_WRLD);
	global.Set("LAND", (uint8_t)FormType::kFormType_LAND);
	global.Set("NAVM", (uint8_t)FormType::kFormType_NAVM);
	global.Set("TLOD", (uint8_t)FormType::kFormType_TLOD);
	global.Set("DIAL", (uint8_t)FormType::kFormType_DIAL);
	global.Set("INFO", (uint8_t)FormType::kFormType_INFO);
	global.Set("QUST", (uint8_t)FormType::kFormType_QUST);
	global.Set("IDLE", (uint8_t)FormType::kFormType_IDLE);
	global.Set("PACK", (uint8_t)FormType::kFormType_PACK);
	global.Set("CSTY", (uint8_t)FormType::kFormType_CSTY);
	global.Set("LSCR", (uint8_t)FormType::kFormType_LSCR);
	global.Set("LVSP", (uint8_t)FormType::kFormType_LVSP);
	global.Set("ANIO", (uint8_t)FormType::kFormType_ANIO);
	global.Set("WATR", (uint8_t)FormType::kFormType_WATR);
	global.Set("EFSH", (uint8_t)FormType::kFormType_EFSH);
	global.Set("TOFT", (uint8_t)FormType::kFormType_TOFT);
	global.Set("EXPL", (uint8_t)FormType::kFormType_EXPL);
	global.Set("DEBR", (uint8_t)FormType::kFormType_DEBR);
	global.Set("IMGS", (uint8_t)FormType::kFormType_IMGS);
	global.Set("IMAD", (uint8_t)FormType::kFormType_IMAD);
	global.Set("FLST", (uint8_t)FormType::kFormType_FLST);
	global.Set("PERK", (uint8_t)FormType::kFormType_PERK);
	global.Set("BPTD", (uint8_t)FormType::kFormType_BPTD);
	global.Set("ADDN", (uint8_t)FormType::kFormType_ADDN);
	global.Set("AVIF", (uint8_t)FormType::kFormType_AVIF);
	global.Set("CAMS", (uint8_t)FormType::kFormType_CAMS);
	global.Set("CPTH", (uint8_t)FormType::kFormType_CPTH);
	global.Set("VTYP", (uint8_t)FormType::kFormType_VTYP);
	global.Set("MATT", (uint8_t)FormType::kFormType_MATT);
	global.Set("IPCT", (uint8_t)FormType::kFormType_IPCT);
	global.Set("IPDS", (uint8_t)FormType::kFormType_IPDS);
	global.Set("ARMA", (uint8_t)FormType::kFormType_ARMA);
	global.Set("ECZN", (uint8_t)FormType::kFormType_ECZN);
	global.Set("LCTN", (uint8_t)FormType::kFormType_LCTN);
	global.Set("MESG", (uint8_t)FormType::kFormType_MESG);
	global.Set("RGDL", (uint8_t)FormType::kFormType_RGDL);
	global.Set("DOBJ", (uint8_t)FormType::kFormType_DOBJ);
	global.Set("DFOB", (uint8_t)FormType::kFormType_DFOB);
	global.Set("LGTM", (uint8_t)FormType::kFormType_LGTM);
	global.Set("MUSC", (uint8_t)FormType::kFormType_MUSC);
	global.Set("FSTP", (uint8_t)FormType::kFormType_FSTP);
	global.Set("FSTS", (uint8_t)FormType::kFormType_FSTS);
	global.Set("SMBN", (uint8_t)FormType::kFormType_SMBN);
	global.Set("SMQN", (uint8_t)FormType::kFormType_SMQN);
	global.Set("SMEN", (uint8_t)FormType::kFormType_SMEN);
	global.Set("DLBR", (uint8_t)FormType::kFormType_DLBR);
	global.Set("MUST", (uint8_t)FormType::kFormType_MUST);
	global.Set("DLVW", (uint8_t)FormType::kFormType_DLVW);
	global.Set("WOOP", (uint8_t)FormType::kFormType_WOOP);
	global.Set("SHOU", (uint8_t)FormType::kFormType_SHOU);
	global.Set("EQUP", (uint8_t)FormType::kFormType_EQUP);
	global.Set("RELA", (uint8_t)FormType::kFormType_RELA);
	global.Set("SCEN", (uint8_t)FormType::kFormType_SCEN);
	global.Set("ASTP", (uint8_t)FormType::kFormType_ASTP);
	global.Set("OTFT", (uint8_t)FormType::kFormType_OTFT);
	global.Set("ARTO", (uint8_t)FormType::kFormType_ARTO);
	global.Set("MATO", (uint8_t)FormType::kFormType_MATO);
	global.Set("MOVT", (uint8_t)FormType::kFormType_MOVT);
	global.Set("SNDR", (uint8_t)FormType::kFormType_SNDR);
	global.Set("DUAL", (uint8_t)FormType::kFormType_DUAL);
	global.Set("SNCT", (uint8_t)FormType::kFormType_SNCT);
	global.Set("SOPM", (uint8_t)FormType::kFormType_SOPM);
	global.Set("COLL", (uint8_t)FormType::kFormType_COLL);
	global.Set("CLFM", (uint8_t)FormType::kFormType_CLFM);
	global.Set("REVB", (uint8_t)FormType::kFormType_REVB);
	global.Set("PKIN", (uint8_t)FormType::kFormType_PKIN);
	global.Set("RFGP", (uint8_t)FormType::kFormType_RFGP);
	global.Set("AMDL", (uint8_t)FormType::kFormType_AMDL);
	global.Set("LAYR", (uint8_t)FormType::kFormType_LAYR);
	global.Set("COBJ", (uint8_t)FormType::kFormType_COBJ);
	global.Set("OMOD", (uint8_t)FormType::kFormType_OMOD);
	global.Set("MSWP", (uint8_t)FormType::kFormType_MSWP);
	global.Set("ZOOM", (uint8_t)FormType::kFormType_ZOOM);
	global.Set("INNR", (uint8_t)FormType::kFormType_INNR);
	global.Set("KSSM", (uint8_t)FormType::kFormType_KSSM);
	global.Set("AECH", (uint8_t)FormType::kFormType_AECH);
	global.Set("SCCO", (uint8_t)FormType::kFormType_SCCO);
	global.Set("AORU", (uint8_t)FormType::kFormType_AORU);
	global.Set("SCSN", (uint8_t)FormType::kFormType_SCSN);
	global.Set("STAG", (uint8_t)FormType::kFormType_STAG);
	global.Set("NOCM", (uint8_t)FormType::kFormType_NOCM);
	global.Set("LENS", (uint8_t)FormType::kFormType_LENS);
	global.Set("LSPR", (uint8_t)FormType::kFormType_LSPR);
	global.Set("GDRY", (uint8_t)FormType::kFormType_GDRY);
	global.Set("OVIS", (uint8_t)FormType::kFormType_OVIS);
	_MESSAGE("Registered FormType constants.");

	LuaActivator::RegisterFunctions(&lua, &global);
	LuaActorBase::RegisterFunctions(&lua, &global);
	LuaActorValue::RegisterFunctions(&lua, &global);
	LuaAmmo::RegisterFunctions(&lua, &global);
	LuaArmor::RegisterFunctions(&lua, &global);
	LuaBook::RegisterFunctions(&lua, &global);
	LuaClass::RegisterFunctions(&lua, &global);
	LuaCombatStyle::RegisterFunctions(&lua, &global);
	LuaComponent::RegisterFunctions(&lua, &global);
	LuaConstructibleObject::RegisterFunctions(&lua, &global);
	LuaContainer::RegisterFunctions(&lua, &global);
	LuaDoor::RegisterFunctions(&lua, &global);
	LuaEnchantment::RegisterFunctions(&lua, &global);
	LuaEncounterZone::RegisterFunctions(&lua, &global);
	LuaEquipSlot::RegisterFunctions(&lua, &global);
	LuaExplosion::RegisterFunctions(&lua, &global);
	LuaFaction::RegisterFunctions(&lua, &global);
	LuaFlora::RegisterFunctions(&lua, &global);
	LuaForm::RegisterFunctions(&lua, &global);
	LuaFurniture::RegisterFunctions(&lua, &global);
	LuaGame::RegisterFunctions(&lua, &global);
	LuaGlobalVariable::RegisterFunctions(&lua, &global);
	LuaHolotape::RegisterFunctions(&lua, &global);
	LuaIngredient::RegisterFunctions(&lua, &global);
	LuaKey::RegisterFunctions(&lua, &global);
	LuaKeyword::RegisterFunctions(&lua, &global);
	LuaLeveledActor::RegisterFunctions(&lua, &global);
	LuaLeveledItem::RegisterFunctions(&lua, &global);
	LuaLeveledSpell::RegisterFunctions(&lua, &global);
	LuaLocation::RegisterFunctions(&lua, &global);
	LuaMagicEffect::RegisterFunctions(&lua, &global);
	LuaMessage::RegisterFunctions(&lua, &global);
	LuaMiscObject::RegisterFunctions(&lua, &global);
	LuaMovableStatic::RegisterFunctions(&lua, &global);
	LuaObjectMod::RegisterFunctions(&lua, &global);
	LuaOutfit::RegisterFunctions(&lua, &global);
	LuaPackage::RegisterFunctions(&lua, &global);
	LuaPerk::RegisterFunctions(&lua, &global);
	LuaPotion::RegisterFunctions(&lua, &global);
	LuaQuest::RegisterFunctions(&lua, &global);
	LuaRace::RegisterFunctions(&lua, &global);
	LuaSpell::RegisterFunctions(&lua, &global);
	LuaSoulGem::RegisterFunctions(&lua, &global);
	LuaStatic::RegisterFunctions(&lua, &global);
	LuaTalkingActivator::RegisterFunctions(&lua, &global);
	LuaTerminal::RegisterFunctions(&lua, &global);
	LuaWeapon::RegisterFunctions(&lua, &global);
	LuaWeather::RegisterFunctions(&lua, &global);

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
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrBOOK);
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