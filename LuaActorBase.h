#pragma once

class Lua;
class LuaTable;

namespace LuaActorBase {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}