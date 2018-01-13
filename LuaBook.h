#pragma once

class Lua;
class LuaTable;

namespace LuaBook {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}