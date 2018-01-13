#pragma once

class Lua;
class LuaTable;

namespace LuaOutfit {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}