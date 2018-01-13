#include "LuaLeveledSpell.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaLeveledSpell::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("LeveledSpell", table);

	_MESSAGE("Registered LeveledSpell functions.");
}
