#pragma once

class Lua;
class LuaTable;

namespace LuaLocation {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}