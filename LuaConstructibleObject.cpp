#include "LuaConstructibleObject.h"

#include <luacppinterface.h>

#include "f4se/GameForms.h"
#include "f4se/GameRTTI.h"

uint16_t LuaConstructibleObject::GetCreatedCount(uint32_t thisFormId) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		return constructibleObject->createdCount;
	}
	return 0;
}
void LuaConstructibleObject::SetCreatedCount(uint32_t thisFormId, uint16_t newCreatedCount) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		constructibleObject->createdCount = newCreatedCount;
	}
}
uint32_t LuaConstructibleObject::GetCreatedObject(uint32_t thisFormId) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject && constructibleObject->createdObject) {
		return constructibleObject->createdObject->formID;
	}
	return 0;
}
void LuaConstructibleObject::SetCreatedObject(uint32_t thisFormId, uint32_t newCreatedObject) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		constructibleObject->createdObject = LookupFormByID(newCreatedObject);
	}
}
uint16_t LuaConstructibleObject::GetPriority(uint32_t thisFormId) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		return constructibleObject->priority;
	}
	return 0;
}
void LuaConstructibleObject::SetPriority(uint32_t thisFormId, uint16_t newPriority) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		constructibleObject->priority = newPriority;
	}
}
uint32_t LuaConstructibleObject::GetWorkbenchKeyword(uint32_t thisFormId) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject && constructibleObject->workbenchKeyword) {
		return constructibleObject->workbenchKeyword->formID;
	}
	return 0;
}
void LuaConstructibleObject::SetWorkbenchKeyword(uint32_t thisFormId, uint32_t newWorkbenchKeyword) {
	BGSConstructibleObject* constructibleObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSConstructibleObject);
	if (constructibleObject) {
		constructibleObject->workbenchKeyword = DYNAMIC_CAST(LookupFormByID(newWorkbenchKeyword), TESForm, BGSKeyword);
	}
}

void LuaConstructibleObject::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetCreatedCount", lua->CreateFunction<uint16_t(uint32_t)>(GetCreatedCount));
	table.Set("SetCreatedCount", lua->CreateFunction<void(uint32_t, uint16_t)>(SetCreatedCount));
	table.Set("GetCreatedObject", lua->CreateFunction<uint32_t(uint32_t)>(GetCreatedObject));
	table.Set("SetCreatedObject", lua->CreateFunction<void(uint32_t, uint32_t)>(SetCreatedObject));
	table.Set("GetPriority", lua->CreateFunction<uint16_t(uint32_t)>(GetPriority));
	table.Set("SetPriority", lua->CreateFunction<void(uint32_t, uint16_t)>(SetPriority));
	table.Set("GetWorkbenchKeyword", lua->CreateFunction<uint32_t(uint32_t)>(GetWorkbenchKeyword));
	table.Set("SetWorkbenchKeyword", lua->CreateFunction<void(uint32_t, uint32_t)>(SetWorkbenchKeyword));

	global->Set("ConstructibleObject", table);

	_MESSAGE("Registered ConstructibleObject functions.");
}
