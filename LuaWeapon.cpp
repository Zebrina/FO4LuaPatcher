#include "LuaWeapon.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaWeapon::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Weapon", table);

	_MESSAGE("Registered Weapon functions.");
}
