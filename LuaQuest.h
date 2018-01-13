#pragma once

class Lua;
class LuaTable;

namespace LuaQuest {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}