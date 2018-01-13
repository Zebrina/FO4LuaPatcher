#pragma once

class Lua;
class LuaTable;

namespace LuaSpell {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}