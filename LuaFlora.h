#pragma once

class Lua;
class LuaTable;

namespace LuaFlora {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}