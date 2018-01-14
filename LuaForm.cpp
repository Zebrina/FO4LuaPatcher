#include "LuaForm.h"

#include <unordered_map>

#include <luacppinterface.h>

#include "LuaUtility.h"
#include "f4se/GameRTTI.h"

uint8_t LuaForm::GetType(uint32_t thisFormId) {
	TESForm* form = LookupFormByID(thisFormId);
	if (form) {
		return form->GetFormType();
	}
	return TESForm::kTypeID;
}
bool LuaForm::IsPlayable(uint32_t thisFormId) {
	TESForm* form = LookupFormByID(thisFormId);
	if (form) {
		enum {
			kFlag_NonPlayable = 1 << 2,
		};
		return !(form->flags & kFlag_NonPlayable);
	}
	return false;
}
const char* LuaForm::GetName(uint32_t thisFormId) {
	TESForm* form = LookupFormByID(thisFormId);
	if (form) {
		const char* fullName = form->GetFullName();
		if (fullName) {
			return fullName;
		}
	}
	return "";
}
void LuaForm::SetName(uint32_t thisFormId, const char* newName) {
	TESFullName* fullName = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, TESFullName);
	if (fullName) {
		_MESSAGE("0x%.8x.SetName: %s -> %s", thisFormId, fullName->name.c_str(), newName);
		fullName->name = BSFixedString(newName);
	}
	else {
		_MESSAGE("0x%.8x.SetName: Fail! Does not have TESFullName.  %s", thisFormId, newName);
	}
}
bool LuaForm::HasKeyword(uint32_t thisFormId, uint32_t keywordFormId) {
	BGSKeywordForm* keywords = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSKeywordForm);
	if (keywords) {
		for (int i{ 0 }; i < keywords->numKeywords; ++i) {
			if (keywords->keywords[i]->formID == keywordFormId) {
				return true;
			}
		}
	}
	return false;
}
bool LuaForm::HasKeywordString(uint32_t thisFormId, const char* keyword) {
	BGSKeyword* keywordForm = GetKeywordByName(keyword);
	if (keywordForm) {
		BGSKeywordForm* keywords = DYNAMIC_CAST(LookupFormByID(thisFormId), TESForm, BGSKeywordForm);
		if (keywords) {
			for (int i{ 0 }; i < keywords->numKeywords; ++i) {
				if (keywords->keywords[i] == keywordForm) {
					return true;
				}
			}
		}
	}
	return false;
}

void LuaForm::RegisterFunctions(Lua* lua, LuaTable* global) {
	LuaTable table = lua->CreateTable();

	table.Set("GetType", lua->CreateFunction<uint8_t(uint32_t)>(LuaForm::GetType));
	table.Set("IsPlayable", lua->CreateFunction<bool(uint32_t)>(LuaForm::IsPlayable));
	table.Set("GetName", lua->CreateFunction<const char*(uint32_t)>(LuaForm::GetName));
	table.Set("SetName", lua->CreateFunction<void(uint32_t, const char*)>(LuaForm::SetName));
	table.Set("HasKeyword", lua->CreateFunction<bool(uint32_t, uint32_t)>(LuaForm::HasKeyword));
	table.Set("HasKeywordString", lua->CreateFunction<bool(uint32_t, const char*)>(LuaForm::HasKeywordString));

	global->Set("Form", table);

	_MESSAGE("Registered Form functions.");
}