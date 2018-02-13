#include "LuaCell.h"

#include <luacppinterface.h>

#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameRTTI.h"

void LuaCell::EnableFastTravel(uint32_t thisFormId, bool flag) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {
		
	}
}
uint32_t LuaCell::GetActorOwner(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
	return 0;
}
void LuaCell::SetActorOwner(uint32_t thisFormId, uint32_t newOwner) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
uint32_t LuaCell::GetFactionOwner(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
	return 0;
}
void LuaCell::SetFactionOwner(uint32_t thisFormId, uint32_t newOwner) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
bool LuaCell::IsAttached(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
	return false;
}
bool LuaCell::IsInterior(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
	return false;
}
bool LuaCell::IsLoaded(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
	return false;
}
void LuaCell::Reset(uint32_t thisFormId) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
void LuaCell::SetFogColor(uint32_t thisFormId, uint32_t nearRed, uint32_t nearGreen, uint32_t nearBlue, uint32_t farRed, uint32_t farGreen, uint32_t farBlue) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
void LuaCell::SetFogPlanes(uint32_t thisFormId, float newNearValue, float newFarValue) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
void LuaCell::SetFogPower(uint32_t thisFormId, float newPower) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}
void LuaCell::SetPublic(uint32_t thisFormId, bool flag) {
	TESObjectCELL* cell = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectCELL);
	if (cell) {

	}
}

void LuaCell::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("EnableFastTravel", lua->CreateFunction<void(uint32_t, bool)>(EnableFastTravel));
	table.Set("GetActorOwner", lua->CreateFunction<uint32_t(uint32_t)>(GetActorOwner));
	table.Set("SetActorOwner", lua->CreateFunction<void(uint32_t, uint32_t)>(SetActorOwner));
	table.Set("GetFactionOwner", lua->CreateFunction<uint32_t(uint32_t)>(GetFactionOwner));
	table.Set("SetFactionOwner", lua->CreateFunction<void(uint32_t, uint32_t)>(SetFactionOwner));
	table.Set("IsAttached", lua->CreateFunction<bool(uint32_t)>(IsAttached));
	table.Set("IsInterior", lua->CreateFunction<bool(uint32_t)>(IsInterior));
	table.Set("IsLoaded", lua->CreateFunction<bool(uint32_t)>(IsLoaded));
	table.Set("Reset", lua->CreateFunction<void(uint32_t)>(Reset));
	table.Set("SetFogColor", lua->CreateFunction<void(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(SetFogColor));
	table.Set("SetFogPlanes", lua->CreateFunction<void(uint32_t, float, float)>(SetFogPlanes));
	table.Set("SetFogPower", lua->CreateFunction<void(uint32_t, float)>(SetFogPower));
	table.Set("SetPublic", lua->CreateFunction<void(uint32_t, bool)>(SetPublic));

	global->Set("Cell", table);

	_MESSAGE("Registered CEll functions.");
}
