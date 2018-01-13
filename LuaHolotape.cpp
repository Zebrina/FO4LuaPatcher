#include "LuaHolotape.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaHolotape::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Holotape", table);

	_MESSAGE("Registered Holotape functions.");
}
