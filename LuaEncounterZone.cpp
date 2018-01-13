#include "LuaEncounterZone.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaEncounterZone::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("EncounterZone", table);

	_MESSAGE("Registered EncounterZone functions.");
}
