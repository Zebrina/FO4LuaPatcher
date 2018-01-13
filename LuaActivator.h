#pragma once

class Lua;
class LuaTable;

namespace LuaActivator {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}