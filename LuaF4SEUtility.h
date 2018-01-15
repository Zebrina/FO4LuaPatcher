#pragma once

#include <unordered_map>
#include <luacppinterface.h>

#include "f4se/GameForms.h"
#include "f4se/GameTypes.h"

struct BSFixedStringHash {
	std::size_t operator()(const BSFixedString& str) const noexcept;
};

typedef std::unordered_map<BSFixedString, BGSKeyword*, BSFixedStringHash> KeywordCache;

class LuaF4SEUtility {
public:
	LuaF4SEUtility(Lua* lua, LuaTable* global);
	~LuaF4SEUtility() = default;

	Lua* getLua() const;
	LuaTable* getGlobal() const;

	BGSKeyword * GetKeywordByName(const char* keyword);

private:
	Lua* lua;
	LuaTable* global;
	KeywordCache keywordCache;
};
extern LuaF4SEUtility* g_lua;
