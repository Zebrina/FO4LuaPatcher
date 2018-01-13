#include "LuaFurniture.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaFurniture::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Furniture", table);

	_MESSAGE("Registered Furniture functions.");
}
