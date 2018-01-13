#pragma once

class Lua;
class LuaTable;

namespace LuaDoor {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}