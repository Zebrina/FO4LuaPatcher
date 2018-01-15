#pragma once

class Lua;
class LuaTable;

namespace LuaMiscObject {
	uint32_t GetComponentCount(uint32_t thisFormId);
	LuaTable GetComponents(uint32_t thisFormId);
	LuaTable GetComponentsEx(uint32_t thisFormId);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}