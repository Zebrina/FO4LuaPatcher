#pragma once

class Lua;
class LuaTable;

namespace LuaGame {
	uint32_t GetFormFromFile(const char* modName, uint32_t relativeFormId);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}