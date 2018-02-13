#pragma once

class Lua;
class LuaTable;

namespace LuaObjectReference {
	uint32_t GetBaseObject(uint32_t thisFormId);
	void SetBaseObject(uint32_t thisFormId, uint32_t newBaseFormId);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}