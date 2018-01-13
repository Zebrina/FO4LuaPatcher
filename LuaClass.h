#pragma once

class Lua;
class LuaTable;

namespace LuaClass {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}