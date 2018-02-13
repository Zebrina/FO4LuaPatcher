#include "LuaEncounterZone.h"

#include <luacppinterface.h>

#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameRTTI.h"

uint32_t LuaEncounterZone::GetLocation(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone && encounterZone->location) {
		return encounterZone->location->formID;
	}
	return 0;
}
void LuaEncounterZone::SetLocation(uint32_t thisFormId, uint32_t newLocationFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		BGSLocation* newLocation = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSLocation);
		if (newLocation) {
			encounterZone->location = newLocation;
		}
	}
}
uint8_t LuaEncounterZone::GetMaxLevel(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		return encounterZone->maxLevel;
	}
	return 0;
}
void LuaEncounterZone::SetMaxLevel(uint32_t thisFormId, uint8_t newMaxLevel) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		encounterZone->maxLevel = newMaxLevel;
	}
}
uint8_t LuaEncounterZone::GetMinLevel(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		return encounterZone->minLevel;
	}
	return 0;
}
void LuaEncounterZone::SetMinLevel(uint32_t thisFormId, uint8_t newMinLevel) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		encounterZone->minLevel = newMinLevel;
	}
}
uint8_t LuaEncounterZone::GetRank(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		return encounterZone->rank;
	}
	return 0;
}
void LuaEncounterZone::SetRank(uint32_t thisFormId, uint8_t newRank) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		encounterZone->rank = newRank;
	}
}
bool LuaEncounterZone::IsNeverResetable(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		return encounterZone->flags & BGSEncounterZone::kFlag_NeverResets;
	}
	return 0;
}
void LuaEncounterZone::SetNeverResetable(uint32_t thisFormId, bool flag) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		if (flag) {
			encounterZone->flags |= BGSEncounterZone::kFlag_NeverResets;
		}
		else {
			encounterZone->flags &= ~BGSEncounterZone::kFlag_NeverResets;
		}
	}
}
bool LuaEncounterZone::IsCombatBoundaryDisabled(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		enum {
			kFlag_DisableCombatBoundary = 1 << 2,
		};
		return encounterZone->flags & kFlag_DisableCombatBoundary;
	}
	return 0;
}
void LuaEncounterZone::SetCombatBoundaryDisabled(uint32_t thisFormId, bool flag) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		enum {
			kFlag_DisableCombatBoundary = 1 << 2,
		};
		if (flag) {
			encounterZone->flags |= kFlag_DisableCombatBoundary;
		}
		else {
			encounterZone->flags &= ~kFlag_DisableCombatBoundary;
		}
	}
}
bool LuaEncounterZone::IsWorkshop(uint32_t thisFormId) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		return encounterZone->flags & BGSEncounterZone::kFlag_Workshop;
	}
	return 0;
}
void LuaEncounterZone::SetWorkshop(uint32_t thisFormId, bool flag) {
	BGSEncounterZone* encounterZone = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSEncounterZone);
	if (encounterZone) {
		if (flag) {
			encounterZone->flags |= BGSEncounterZone::kFlag_Workshop;
		}
		else {
			encounterZone->flags &= ~BGSEncounterZone::kFlag_Workshop;
		}
	}
}

void LuaEncounterZone::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetLocation", lua->CreateFunction<uint32_t(uint32_t)>(GetLocation));
	table.Set("SetLocation", lua->CreateFunction<void(uint32_t, uint32_t)>(SetLocation));
	table.Set("GetMaxLevel", lua->CreateFunction<uint8_t(uint32_t)>(GetMaxLevel));
	table.Set("SetMaxLevel", lua->CreateFunction<void(uint32_t, uint8_t)>(SetMaxLevel));
	table.Set("GetMinLevel", lua->CreateFunction<uint8_t(uint32_t)>(GetMinLevel));
	table.Set("SetMinLevel", lua->CreateFunction<void(uint32_t, uint8_t)>(SetMinLevel));
	table.Set("GetRank", lua->CreateFunction<uint8_t(uint32_t)>(GetRank));
	table.Set("SetRank", lua->CreateFunction<void(uint32_t, uint8_t)>(SetRank));
	table.Set("IsNeverResetable", lua->CreateFunction<bool(uint32_t)>(IsNeverResetable));
	table.Set("SetNeverResetable", lua->CreateFunction<void(uint32_t, bool)>(SetNeverResetable));
	table.Set("IsCombatBoundaryDisabled", lua->CreateFunction<bool(uint32_t)>(IsCombatBoundaryDisabled));
	table.Set("SetCombatBoundaryDisabled", lua->CreateFunction<void(uint32_t, bool)>(SetCombatBoundaryDisabled));
	table.Set("IsWorkshop", lua->CreateFunction<bool(uint32_t)>(IsWorkshop));
	table.Set("SetWorkshop", lua->CreateFunction<void(uint32_t, bool)>(SetWorkshop));

	global->Set("EncounterZone", table);

	_MESSAGE("Registered EncounterZone functions.");
}
