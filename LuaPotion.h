#pragma once

class Lua;
class LuaTable;

namespace LuaPotion {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}