#include "LuaActorBase.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaActorBase::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("ActorBase", table);

	_MESSAGE("Registered ActorBase functions.");
}
