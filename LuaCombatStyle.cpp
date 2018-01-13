#include "LuaCombatStyle.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaCombatStyle::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("CombatStyle", table);

	_MESSAGE("Registered CombatStyle functions.");
}
