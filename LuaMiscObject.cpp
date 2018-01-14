#include "LuaMiscObject.h"

#include <luacppinterface.h>

#include "f4se/GameObjects.h"
#include "f4se/GameRTTI.h"

uint32_t LuaMiscObject::GetComponentCount(uint32_t thisFormId) {
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		return miscObject->components->count;
	}
	return 0;
}
uint32_t LuaMiscObject::GetComponents(uint32_t thisFormId, LuaTable componentTableOut) {
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		for (int i = 0; i < miscObject->components->count; ++i) {
			componentTableOut.Set<uint32_t>(i + 1, (*miscObject->components)[i].component->formID);
		}
		return miscObject->components->count;
	}
	return 0;
}
uint32_t LuaMiscObject::GetComponentsEx(uint32_t thisFormId, LuaTable componentTableOut) {
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		for (int i = 0; i < miscObject->components->count; ++i) {
			componentTableOut.Set<uint32_t>(i + 1, (*miscObject->components)[i].component->formID);
		}
		return miscObject->components->count;
	}
	return 0;
}

void LuaMiscObject::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetComponentCount", lua->CreateFunction<uint32_t(uint32_t)>(LuaMiscObject::GetComponentCount));
	table.Set("GetComponents", lua->CreateFunction<uint32_t(uint32_t, LuaTable)>(LuaMiscObject::GetComponents));
	//table.Set("GetComponentsEx", lua->CreateFunction<uint32_t(uint32_t, LuaTable)>(LuaMiscObject::GetComponentsEx));

	global->Set("MiscObject", table);

	_MESSAGE("Registered MiscObject functions.");
}
