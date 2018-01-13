#include "LuaMessage.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaMessage::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Message", table);

	_MESSAGE("Registered Message functions.");
}
