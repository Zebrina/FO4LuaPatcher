#include "LuaScriptProcessor.h"

#include <fstream>
#include <sstream>

#include <Windows.h>
#include <luacppinterface.h>

#include "f4se/GameAPI.h"
#include "f4se/GameForms.h"
#include "f4se/GameReferences.h"
#include "f4se/GameData.h"
#include "f4se/GameTypes.h"

#include "LuaF4SEUtility.h"

#include "LuaActivator.h"
#include "LuaActorBase.h"
#include "LuaActorValue.h"
#include "LuaAmmo.h"
#include "LuaArmor.h"
#include "LuaBook.h"
#include "LuaCell.h"
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
#include "LuaObjectReference.h"
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
					script << "InvokeCallback(" << form->formID << "," << (UInt32)form->GetFormType() << ")";

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
	g_lua = new LuaF4SEUtility(&lua, &global);

	lua.LoadStandardLibraries();
	_MESSAGE("Loaded standard libraries.");

	// Redirect print to in-game console.
	global.Set("print", lua.CreateFunction<void(const char*)>(LuaPrint));
	_MESSAGE("Registered print.");

	global.Set("Player", (uint32_t)(*g_player)->formID);

	LuaActivator::RegisterFunctions(&lua, &global);
	LuaActorBase::RegisterFunctions(&lua, &global);
	LuaActorValue::RegisterFunctions(&lua, &global);
	LuaAmmo::RegisterFunctions(&lua, &global);
	LuaArmor::RegisterFunctions(&lua, &global);
	LuaBook::RegisterFunctions(&lua, &global);
	LuaCell::RegisterFunctions(&lua, &global);
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
	LuaObjectReference::RegisterFunctions(&lua, &global);
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

	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrKYWD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLCRT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAACT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTRNS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCMPO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTXST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMICN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrGLOB);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDMGT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCLAS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFACT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrHDPT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrEYES);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRACE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSOUN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrASPC);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSKIL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMGEF);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCPT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLTEX);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrENCH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSPEL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCRL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrACTI);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTACT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrARMO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrBOOK);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCONT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDOOR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrINGR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLIGH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMISC);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSTAT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCOL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMSTT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrGRAS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTREE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFLOR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFURN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWEAP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAMMO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNPC_);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLVLN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrKEYM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrALCH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIDLM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNOTE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPROJ);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrHAZD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrBNDS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSLGM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTERM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLVLI);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWTHR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCLMT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSPGD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRFCT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrREGN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNAVI);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCELL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrREFR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrACHR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPMIS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPARW);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPGRE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPBEA);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPFLA);
	//ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPCON);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPBAR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPHZD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWRLD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLAND);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNAVM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTLOD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDIAL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrINFO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrQUST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIDLE);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPACK);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCSTY);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLSCR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLVSP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrANIO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWATR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrEFSH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrTOFT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrEXPL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDEBR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIMGS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIMAD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFLST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPERK);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrBPTD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrADDN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAVIF);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCAMS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCPTH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrVTYP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMATT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIPCT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrIPDS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrARMA);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrECZN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLCTN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMESG);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRGDL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDOBJ);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDFOB);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLGTM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMUSC);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFSTP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrFSTS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSMBN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSMQN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSMEN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDLBR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMUST);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDLVW);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrWOOP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSHOU);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrEQUP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRELA);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCEN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrASTP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrOTFT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrARTO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMATO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMOVT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSNDR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrDUAL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSNCT);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSOPM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCOLL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCLFM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrREVB);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrPKIN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrRFGP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAMDL);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLAYR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrCOBJ);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrOMOD);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrMSWP);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrZOOM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrINNR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrKSSM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAECH);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCCO);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrAORU);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSCSN);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrSTAG);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrNOCM);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLENS);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrLSPR);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrGDRY);
	ForEachFormInvokeCallbacks(&lua, &global, &callbacks, dataHandler->arrOVIS);

	delete g_lua;

	LUA_DEBUG_PRINT("Lua Patcher finished.");
}
