#pragma once

class Lua;
class LuaTable;

namespace LuaContainer {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}