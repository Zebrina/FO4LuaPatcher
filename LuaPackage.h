#pragma once

class Lua;
class LuaTable;

namespace LuaPackage {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}