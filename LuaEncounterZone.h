#pragma once

class Lua;
class LuaTable;

namespace LuaEncounterZone {
	uint32_t GetLocation(uint32_t thisFormId);
	void SetLocation(uint32_t thisFormId, uint32_t newLocationFormId);
	uint8_t GetMaxLevel(uint32_t thisFormId);
	void SetMaxLevel(uint32_t thisFormId, uint8_t newMaxLevel);
	uint8_t GetMinLevel(uint32_t thisFormId);
	void SetMinLevel(uint32_t thisFormId, uint8_t newMinLevel);
	uint8_t GetRank(uint32_t thisFormId);
	void SetRank(uint32_t thisFormId, uint8_t newRank);
	bool IsNeverResetable(uint32_t thisFormId);
	void SetNeverResetable(uint32_t thisFormId, bool flag);
	bool IsCombatBoundaryDisabled(uint32_t thisFormId);
	void SetCombatBoundaryDisabled(uint32_t thisFormId, bool flag);
	bool IsWorkshop(uint32_t thisFormId);
	void SetWorkshop(uint32_t thisFormId, bool flag);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}