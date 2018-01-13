#include "LuaConstructibleObject.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaConstructibleObject::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("ConstructibleObject", table);

	_MESSAGE("Registered ConstructibleObject functions.");
}
