#include "LuaGame.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameRTTI.h"

#include <luacppinterface.h>

uint32_t LuaGame::GetFormFromFile(const char* modName, uint32_t relativeFormId) {
	DataHandler* dataHandler = *g_dataHandler;
	UInt8 loadedModIndex = dataHandler->GetLoadedModIndex(modName);
	if (loadedModIndex != 0xff) {
		TESForm* form = LookupFormByID((loadedModIndex << 24) | relativeFormId);
		if (form) {
			return form->formID;
		}
	}
	return 0;
}

void LuaGame::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetFormFromFile", lua->CreateFunction<uint32_t(const char*, uint32_t)>(LuaGame::GetFormFromFile));

	global->Set("Game", table);

	_MESSAGE("Registered Game functions.");
}