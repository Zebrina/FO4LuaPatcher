#include "LuaAmmo.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaAmmo::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Ammo", table);

	_MESSAGE("Registered Ammo functions.");
}
