#pragma once

class Lua;
class LuaTable;

namespace LuaFurniture {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}