#pragma once

class Lua;
class LuaTable;

namespace LuaRace {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}