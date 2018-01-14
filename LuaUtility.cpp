#include "LuaUtility.h"

#include "f4se/GameData.h"

//typedef std::unordered_map<BSFixedString, BGSKeyword*, BSFixedStringHash> KeywordCache;
//KeywordCache* keywordCache = new KeywordCache();

std::size_t BSFixedStringHash::operator()(const BSFixedString& str) const noexcept {
	return (std::size_t)str.data;
}

BGSKeyword* GetKeywordByName(const char* keyword) {
	/*
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
	*/
	BSFixedString keywordStr(keyword);
	DataHandler* dataHandler = *g_dataHandler;
	for (SInt32 i = 0; i < dataHandler->arrKYWD.count; ++i) {
		BGSKeyword* keywordForm = dataHandler->arrKYWD[i];
		if (keywordForm->GetEditorID() == keywordStr) {
			return keywordForm;
		}
	}
	return nullptr;
}