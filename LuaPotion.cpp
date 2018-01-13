#include "LuaPotion.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaPotion::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Potion", table);

	_MESSAGE("Registered Potion functions.");
}
