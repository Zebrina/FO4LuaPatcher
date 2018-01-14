#pragma once

class Lua;
class LuaTable;

namespace LuaConstructibleObject {
	uint16_t GetCreatedCount(uint32_t thisFormId);
	void SetCreatedCount(uint32_t thisFormId, uint16_t newCreatedCount);
	uint32_t GetCreatedObject(uint32_t thisFormId);
	void SetCreatedObject(uint32_t thisFormId, uint32_t newCreatedObject);
	uint16_t GetPriority(uint32_t thisFormId);
	void SetPriority(uint32_t thisFormId, uint16_t newPriority);
	uint32_t GetWorkbenchKeyword(uint32_t thisFormId);
	void SetWorkbenchKeyword(uint32_t thisFormId, uint32_t newWorkbenchKeyword);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}