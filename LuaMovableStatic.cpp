#include "LuaMovableStatic.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaMovableStatic::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("MovableStatic", table);

	_MESSAGE("Registered MovableStatic functions.");
}
