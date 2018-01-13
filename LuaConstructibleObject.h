#pragma once

class Lua;
class LuaTable;

namespace LuaConstructibleObject {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}