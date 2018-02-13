#include "LuaObjectReference.h"

#include <luacppinterface.h>

#include "f4se/GameReferences.h"
#include "f4se/GameRTTI.h"

uint32_t LuaObjectReference::GetBaseObject(uint32_t thisFormId) {
	TESObjectREFR* objectReference = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectREFR);
	if (objectReference && objectReference->baseForm) {
		return objectReference->baseForm->formID;
	}
	return 0;
}
void LuaObjectReference::SetBaseObject(uint32_t thisFormId, uint32_t newBaseFormId) {
	TESObjectREFR* objectReference = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectREFR);
	if (objectReference) {
		TESForm* newBaseForm = LookupFormByID(newBaseFormId);
		if (newBaseForm) {
			objectReference->baseForm = LookupFormByID(newBaseFormId);
			//_MESSAGE("0x%.8x.SetBaseObject: %s -> %s", thisFormId, objectReference->GetFullName(), objectReference->baseForm->GetFullName());
		}
	}
}

void LuaObjectReference::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetBaseObject", lua->CreateFunction<uint32_t(uint32_t)>(GetBaseObject));
	table.Set("SetBaseObject", lua->CreateFunction<void(uint32_t, uint32_t)>(SetBaseObject));

	global->Set("ObjectReference", table);

	_MESSAGE("Registered Book functions.");
}
