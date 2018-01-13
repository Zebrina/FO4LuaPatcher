#pragma once

class Lua;
class LuaTable;

namespace LuaMiscObject {
	uint32_t GetComponentCount(uint32_t formId);
	uint32_t GetComponents(uint32_t formId, LuaTable componentTableOut);
	uint32_t GetComponentsEx(uint32_t formId, LuaTable componentTableOut);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}