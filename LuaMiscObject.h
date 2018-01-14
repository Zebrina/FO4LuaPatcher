#pragma once

class Lua;
class LuaTable;

namespace LuaMiscObject {
	uint32_t GetComponentCount(uint32_t thisFormId);
	uint32_t GetComponents(uint32_t thisFormId, LuaTable componentTableOut);
	uint32_t GetComponentsEx(uint32_t thisFormId, LuaTable componentTableOut);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}