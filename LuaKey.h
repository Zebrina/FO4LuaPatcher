#pragma once

class Lua;
class LuaTable;

namespace LuaKey {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}