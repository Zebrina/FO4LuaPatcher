#include "LuaLeveledItem.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaLeveledItem::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("LeveledItem", table);

	_MESSAGE("Registered LeveledItem functions.");
}
