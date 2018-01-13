#pragma once

class Lua;
class LuaTable;

namespace LuaFaction {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}