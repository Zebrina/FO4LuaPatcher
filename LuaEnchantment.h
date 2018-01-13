#pragma once

class Lua;
class LuaTable;

namespace LuaEnchantment {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}