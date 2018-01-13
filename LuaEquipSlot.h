#pragma once

class Lua;
class LuaTable;

namespace LuaEquipSlot {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}