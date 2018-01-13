#pragma once

class Lua;
class LuaTable;

namespace LuaLeveledItem {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}