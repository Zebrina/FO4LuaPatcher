#pragma once

class Lua;
class LuaTable;

namespace LuaForm {
	uint8_t GetType(uint32_t formId);
	bool IsPlayable(uint32_t formId);
	const char* GetName(uint32_t formId);
	void SetName(uint32_t formId, const char* newName);
	bool HasKeyword(uint32_t formId, uint32_t keywordFormId);
	bool HasKeywordString(uint32_t formId, const char* keyword);

	void RegisterFunctions(Lua* lua, LuaTable* global);
	void ClearCaches();
}