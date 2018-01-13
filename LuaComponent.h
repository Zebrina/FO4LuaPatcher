#pragma once

class Lua;
class LuaTable;

namespace LuaComponent {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}