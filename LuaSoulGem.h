#pragma once

class Lua;
class LuaTable;

namespace LuaSoulGem {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}