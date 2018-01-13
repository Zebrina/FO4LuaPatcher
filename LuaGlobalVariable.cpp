#include "LuaGlobalVariable.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaGlobalVariable::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("GlobalVariable", table);

	_MESSAGE("Registered GlobalVariable functions.");
}
