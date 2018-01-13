#pragma once

class Lua;
class LuaTable;

namespace LuaEncounterZone {
	void RegisterFunctions(Lua* lua, LuaTable* global);
}