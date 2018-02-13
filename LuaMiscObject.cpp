#include "LuaMiscObject.h"

#include <luacppinterface.h>

#include "LuaF4SEUtility.h"
#include "f4se/GameObjects.h"
#include "f4se/GameRTTI.h"

uint32_t LuaMiscObject::GetComponentCount(uint32_t thisFormId) {
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		return miscObject->components->count;
	}
	return 0;
}
LuaTable LuaMiscObject::GetComponents(uint32_t thisFormId) {
	LuaTable componentTable = g_lua->getLua()->CreateTable();
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		for (int i = 0; i < miscObject->components->count; ++i) {
			componentTable.Set<uint32_t>(i + 1, (*miscObject->components)[i].component->formID);
		}
		return componentTable;
	}
	return componentTable;
}
LuaTable LuaMiscObject::GetComponentsEx(uint32_t thisFormId) {
	LuaTable componentTable = g_lua->getLua()->CreateTable();
	TESObjectMISC* miscObject = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESObjectMISC);
	if (miscObject && miscObject->components) {
		for (int i = 0; i < miscObject->components->count; ++i) {
			componentTable.Set<uint32_t>(i + 1, (*miscObject->components)[i].component->formID);
		}
		return componentTable;
	}
	return componentTable;
}

void LuaMiscObject::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetComponentCount", lua->CreateFunction<uint32_t(uint32_t)>(GetComponentCount));
	table.Set("GetComponents", lua->CreateFunction<LuaTable(uint32_t)>(GetComponents));
	//table.Set("GetComponentsEx", lua->CreateFunction<LuaTable(uint32_t)>(GetComponentsEx));

	global->Set("MiscObject", table);

	_MESSAGE("Registered MiscObject functions.");
}
