#pragma once

class Lua;
class LuaTable;

namespace LuaAmmo {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}