#pragma once

class Lua;
class LuaTable;

namespace LuaMagicEffect {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}