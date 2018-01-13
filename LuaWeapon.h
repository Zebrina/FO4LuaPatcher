#pragma once

class Lua;
class LuaTable;

namespace LuaWeapon {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}