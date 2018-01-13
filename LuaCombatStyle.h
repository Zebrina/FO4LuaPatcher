#pragma once

class Lua;
class LuaTable;

namespace LuaCombatStyle {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}