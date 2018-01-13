#pragma once

class Lua;
class LuaTable;

namespace LuaMessage {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}