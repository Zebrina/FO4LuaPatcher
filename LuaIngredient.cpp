#include "LuaIngredient.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaIngredient::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Ingredient", table);

	_MESSAGE("Registered Ingredient functions.");
}
