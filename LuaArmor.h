#pragma once

class Lua;
class LuaTable;

namespace LuaArmor {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}