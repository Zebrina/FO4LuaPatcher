#pragma once

class Lua;
class LuaTable;

namespace LuaTerminal {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}