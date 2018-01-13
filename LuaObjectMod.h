#pragma once

class Lua;
class LuaTable;

namespace LuaObjectMod {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}