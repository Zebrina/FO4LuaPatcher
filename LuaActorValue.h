#pragma once

class Lua;
class LuaTable;

namespace LuaActorValue {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}