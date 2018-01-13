#include "LuaExplosion.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaExplosion::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Explosion", table);

	_MESSAGE("Registered Explosion functions.");
}
