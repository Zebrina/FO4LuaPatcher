#include "LuaTalkingActivator.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaTalkingActivator::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("TalkingActivator", table);

	_MESSAGE("Registered TalkingActivator functions.");
}
