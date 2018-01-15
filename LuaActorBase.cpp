#include "LuaActorBase.h"

#include <luacppinterface.h>

#include "LuaF4SEUtility.h"

void LuaActorBase::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("ActorBase", table);

	_MESSAGE("Registered ActorBase functions.");
}
