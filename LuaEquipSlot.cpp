#include "LuaEquipSlot.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaEquipSlot::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("EquipSlot", table);

	_MESSAGE("Registered EquipSlot functions.");
}
