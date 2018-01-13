#pragma once

class Lua;
class LuaTable;

namespace LuaPerk {
	uint8_t GetLevel(uint32_t thisFormId);
	void SetLevel(uint32_t thisFormId, uint8_t newLevel);
	uint32_t GetNextPerk(uint32_t thisFormId);
	uint8_t GetNumRanks(uint32_t thisFormId);
	const char* GetSWFPath(uint32_t thisFormId);
	bool IsHidden(uint32_t thisFormId);
	bool IsPlayable(uint32_t thisFormId);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}