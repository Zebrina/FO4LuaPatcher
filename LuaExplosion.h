#pragma once

class Lua;
class LuaTable;

namespace LuaExplosion {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}