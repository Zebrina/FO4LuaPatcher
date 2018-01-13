#pragma once

class Lua;
class LuaTable;

namespace LuaMovableStatic {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}