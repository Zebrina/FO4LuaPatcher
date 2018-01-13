#include "LuaObjectMod.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaObjectMod::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("ObjectMod", table);

	_MESSAGE("Registered ObjectMod functions.");
}
