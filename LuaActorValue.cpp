#include "LuaActorValue.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaActorValue::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("ActorValue", table);

	_MESSAGE("Registered ActorValue functions.");
}
