#pragma once

class Lua;
class LuaTable;

namespace LuaLeveledSpell {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}