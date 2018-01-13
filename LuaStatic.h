#pragma once

class Lua;
class LuaTable;

namespace LuaStatic {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}