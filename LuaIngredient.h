#pragma once

class Lua;
class LuaTable;

namespace LuaIngredient {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}