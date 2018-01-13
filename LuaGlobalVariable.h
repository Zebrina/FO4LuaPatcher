#pragma once

class Lua;
class LuaTable;

namespace LuaGlobalVariable {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}