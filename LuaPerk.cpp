#include "LuaPerk.h"

#include <luacppinterface.h>

#include "LuaF4SEUtility.h"
#include "f4se/GameRTTI.h"

uint8_t LuaPerk::GetLevel(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		return perk->perkLevel;
	}
	return 0;
}
void LuaPerk::SetLevel(uint32_t thisFormId, uint8_t newLevel) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		_MESSAGE("0x%.8x.SetLevel: (%s) %i -> %i", thisFormId, perk->GetFullName(), perk->perkLevel, newLevel);
		perk->perkLevel = newLevel;
	}
}
uint32_t LuaPerk::GetNextPerk(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk && perk->nextPerk) {
		return perk->nextPerk->formID;
	}
	return 0;
}
uint8_t LuaPerk::GetNumRanks(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		return perk->numRanks;
	}
	return 0;
}
const char* LuaPerk::GetSWFPath(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		return perk->swfPath.c_str();
	}
	return 0;
}
bool LuaPerk::IsHidden(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		return perk->hidden;
	}
	return 0;
}
void LuaPerk::SetHidden(uint32_t thisFormId, bool isHidden) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		perk->hidden = (UInt8)isHidden;
	}
}
bool LuaPerk::IsPlayable(uint32_t thisFormId) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		return perk->playable;
	}
	return 0;
}
void LuaPerk::SetPlayable(uint32_t thisFormId, bool isPlayable) {
	BGSPerk* perk = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSPerk);
	if (perk) {
		perk->playable = (UInt8)isPlayable;
	}
}

void LuaPerk::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetLevel", lua->CreateFunction<uint8_t(uint32_t)>(GetLevel));
	table.Set("SetLevel", lua->CreateFunction<void(uint32_t, uint8_t)>(SetLevel));
	table.Set("GetNextPerk", lua->CreateFunction<uint32_t(uint32_t)>(GetNextPerk));
	table.Set("GetNumRanks", lua->CreateFunction<uint8_t(uint32_t)>(GetNumRanks));
	table.Set("GetSWFPath", lua->CreateFunction<const char*(uint32_t)>(GetSWFPath));
	table.Set("IsHidden", lua->CreateFunction<bool(uint32_t)>(IsHidden));
	table.Set("SetHidden", lua->CreateFunction<void(uint32_t, bool)>(SetPlayable));
	table.Set("IsPlayable", lua->CreateFunction<bool(uint32_t)>(IsPlayable));
	table.Set("SetPlayable", lua->CreateFunction<void(uint32_t, bool)>(SetPlayable));

	global->Set("Perk", table);

	_MESSAGE("Registered Perk functions.");
}
