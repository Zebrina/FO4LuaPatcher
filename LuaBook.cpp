#include "LuaBook.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaBook::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Book", table);

	_MESSAGE("Registered Book functions.");
}
