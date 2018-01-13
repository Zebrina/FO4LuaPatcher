#include "LuaLeveledActor.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaLeveledActor::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("LeveledActor", table);

	_MESSAGE("Registered LeveledActor functions.");
}
