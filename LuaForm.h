#pragma once

class Lua;
class LuaTable;

namespace LuaForm {
	uint8_t GetType(uint32_t thisFormId);
	bool IsPlayable(uint32_t thisFormId);
	const char* GetName(uint32_t thisFormId);
	void SetName(uint32_t thisFormId, const char* newName);
	bool HasKeyword(uint32_t thisFormId, uint32_t keywordFormId);
	bool HasKeywordString(uint32_t thisFormId, const char* keyword);

	void RegisterFunctions(Lua* lua, LuaTable* global);
}