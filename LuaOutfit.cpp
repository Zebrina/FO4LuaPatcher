#include "LuaOutfit.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaOutfit::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Outfit", table);

	_MESSAGE("Registered Outfit functions.");
}
