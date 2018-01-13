#include "LuaSoulGem.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaSoulGem::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("SoulGem", table);

	_MESSAGE("Registered SoulGem functions.");
}
