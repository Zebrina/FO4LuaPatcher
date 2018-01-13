#include "LuaMagicEffect.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaMagicEffect::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("MagicEffect", table);

	_MESSAGE("Registered MagicEffect functions.");
}
