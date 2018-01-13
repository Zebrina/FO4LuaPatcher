#pragma once

class Lua;
class LuaTable;

namespace LuaWeather {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}