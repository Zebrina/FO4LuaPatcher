#pragma once

class Lua;
class LuaTable;

namespace LuaLeveledActor {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}