#pragma once

class Lua;
class LuaTable;

namespace LuaTalkingActivator {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}