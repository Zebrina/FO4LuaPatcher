#include "LuaF4SEUtility.h"

#include "f4se/GameData.h"

LuaF4SEUtility* g_lua = nullptr;

std::size_t BSFixedStringHash::operator()(const BSFixedString& str) const noexcept {
	return (std::size_t)str.data;
}

LuaF4SEUtility::LuaF4SEUtility(Lua* lua, LuaTable* global) :
	lua(lua),
	global(global) {
}

Lua* LuaF4SEUtility::getLua() const {
	return lua;
}
LuaTable* LuaF4SEUtility::getGlobal() const {
	return global;
}

BGSKeyword* LuaF4SEUtility::GetKeywordByName(const char* keywordName) {
	BSFixedString keywordStr(keywordName);
	auto found = keywordCache.find(keywordStr);
	if (found == keywordCache.end()) {
		DataHandler* dataHandler = *g_dataHandler;
		for (SInt32 i = 0; i < dataHandler->arrKYWD.count; ++i) {
			BGSKeyword* keywordForm = dataHandler->arrKYWD[i];
			if (keywordForm->GetEditorID() == keywordStr) {
				keywordCache.insert({ keywordStr, keywordForm });
				return keywordForm;
			}
		}
		// Not found. Add nullptr to keyword cache.
		_MESSAGE("GetKeywordByName: Keyword %s not found.", keywordStr);
		keywordCache.insert({ keywordStr, nullptr });
		return nullptr;
	}
	return found->second;
}