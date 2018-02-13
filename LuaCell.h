#pragma once

class Lua;
class LuaTable;

namespace LuaCell {
	void EnableFastTravel(uint32_t thisFormId, bool flag);
	uint32_t GetActorOwner(uint32_t thisFormId);
	void SetActorOwner(uint32_t thisFormId, uint32_t newOwner);
	uint32_t GetFactionOwner(uint32_t thisFormId);
	void SetFactionOwner(uint32_t thisFormId, uint32_t newOwner);
	bool IsAttached(uint32_t thisFormId);
	bool IsInterior(uint32_t thisFormId);
	bool IsLoaded(uint32_t thisFormId);
	void Reset(uint32_t thisFormId);
	void SetFogColor(uint32_t thisFormId, uint32_t nearRed, uint32_t nearGreen, uint32_t nearBlue, uint32_t farRed, uint32_t farGreen, uint32_t farBlue);
	void SetFogPlanes(uint32_t thisFormId, float newNearValue, float newFarValue);
	void SetFogPower(uint32_t thisFormId, float newPower);
	void SetPublic(uint32_t thisFormId, bool flag);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}