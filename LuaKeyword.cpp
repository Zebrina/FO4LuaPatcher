#include "LuaKeyword.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaKeyword::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Keyword", table);

	_MESSAGE("Registered Keyword functions.");
}
