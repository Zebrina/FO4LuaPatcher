#pragma once

class Lua;
class LuaTable;

namespace LuaKeyword {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}