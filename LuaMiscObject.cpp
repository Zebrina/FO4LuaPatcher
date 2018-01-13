#include "LuaMiscObject.h"

#include "f4se/GameForms.h"
#include "f4se/GameData.h"

#include <luacppinterface.h>

uint32_t LuaMiscObject::GetComponentCount(uint32_t formId) {
	TESForm* form = LookupFormByID(formId);
	if (form && form->GetFormType() == FormType::kFormType_MISC) {
		TESObjectMISC* misc = static_cast<TESObjectMISC*>(form);
		if (misc->components) {
			return misc->components->count;
		}
	}
	return 0;
}
uint32_t LuaMiscObject::GetComponents(uint32_t formId, LuaTable componentTableOut) {
	TESForm* form = LookupFormByID(formId);
	if (form && form->GetFormType() == FormType::kFormType_MISC) {
		TESObjectMISC* misc = static_cast<TESObjectMISC*>(form);
		if (misc->components) {
			for (int i = 0; i < misc->components->count; ++i) {
				componentTableOut.Set<uint32_t>(i + 1, (*misc->components)[i].component->formID);
			}
			return misc->components->count;
		}
	}
	return 0;
}
uint32_t LuaMiscObject::GetComponentsEx(uint32_t formId, LuaTable componentTableOut) {
	TESForm* form = LookupFormByID(formId);
	if (form && form->GetFormType() == FormType::kFormType_MISC) {
		TESObjectMISC* misc = static_cast<TESObjectMISC*>(form);
		if (misc->components) {
			for (int i = 0; i < misc->components->count; ++i) {
				componentTableOut.Set<uint32_t>(i + 1, (*misc->components)[i].component->formID);
			}
			return misc->components->count;
		}
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
