#include "LuaForm.h"

#include <unordered_map>

#include "f4se/GameForms.h"
#include "f4se/GameData.h"
#include "f4se/GameRTTI.h"

#include <luacppinterface.h>

struct BSFixedStringHash {
	std::size_t operator()(const BSFixedString& str) const noexcept {
		return (std::size_t)str.data;
	}
};
typedef std::unordered_map<BSFixedString, BGSKeyword*, BSFixedStringHash> KeywordCache;
KeywordCache* keywordCache = new KeywordCache();

BGSKeyword* GetKeywordByName(BSFixedString keyword) {
	auto found = keywordCache->find(keyword);
	if (found == keywordCache->end()) {
		DataHandler* dataHandler = *g_dataHandler;
		for (SInt32 i = 0; i < dataHandler->arrKYWD.count; ++i) {
			BGSKeyword* keywordForm = dataHandler->arrKYWD[i];
			if (keywordForm->GetEditorID() == keyword) {
				keywordCache->insert({ keyword, keywordForm });
				return keywordForm;
			}
		}
		// Not found. Add nullptr to keyword cache.
		_MESSAGE("GetKeywordByName: Keyword %s not found.", keyword.c_str());
		keywordCache->insert({ keyword, nullptr });
		return nullptr;
	}
	return found->second;
}

uint8_t LuaForm::GetType(uint32_t formId) {
	TESForm* form = LookupFormByID(formId);
	if (form) {
		return form->GetFormType();
	}
	return TESForm::kTypeID;
}
bool LuaForm::IsPlayable(uint32_t formId) {
	TESForm* form = LookupFormByID(formId);
	if (form) {
		enum {
			kFlag_NonPlayable = 1 << 2,
		};
		return !(form->flags & kFlag_NonPlayable);
	}
	return false;
}
const char* LuaForm::GetName(uint32_t formId) {
	TESForm* form = LookupFormByID(formId);
	if (form) {
		const char* fullName = form->GetFullName();
		if (fullName) {
			return fullName;
		}
	}
	return "";
}
void LuaForm::SetName(uint32_t formId, const char* newName) {
	TESFullName* fullName = DYNAMIC_CAST(LookupFormByID(formId), TESForm, TESFullName);
	if (fullName) {
		_MESSAGE("0x%.8x.SetName: %s -> %s", formId, fullName->name.c_str(), newName);
		fullName->name = BSFixedString(newName);
	}
}
bool LuaForm::HasKeyword(uint32_t formId, uint32_t keywordFormId) {
	BGSKeywordForm* keywords{ DYNAMIC_CAST(LookupFormByID(formId), TESForm, BGSKeywordForm) };
	if (keywords) {
		for (int i{ 0 }; i < keywords->numKeywords; ++i) {
			if (keywords->keywords[i]->formID == keywordFormId) {
				return true;
			}
		}
	}
}
bool LuaForm::HasKeywordString(uint32_t formId, const char* keyword) {
	BGSKeyword* keywordForm = GetKeywordByName(BSFixedString(keyword));
	if (keywordForm) {
		BGSKeywordForm* keywords{ DYNAMIC_CAST(LookupFormByID(formId), TESForm, BGSKeywordForm) };
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
}
void LuaForm::ClearCaches() {
	delete keywordCache;
	keywordCache = nullptr;
}