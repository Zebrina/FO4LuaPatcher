#include "LuaLocation.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaLocation::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Location", table);

	_MESSAGE("Registered Location functions.");
}
