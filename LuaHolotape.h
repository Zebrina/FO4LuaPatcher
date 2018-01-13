#pragma once

class Lua;
class LuaTable;

namespace LuaHolotape {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}