#include "LuaEnchantment.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

void LuaEnchantment::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();



	global->Set("Enchantment", table);

	_MESSAGE("Registered Enchantment functions.");
}
