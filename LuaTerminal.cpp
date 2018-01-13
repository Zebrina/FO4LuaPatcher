#include "LuaTerminal.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaTerminal::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Terminal", table);

	_MESSAGE("Registered Terminal functions.");
}
