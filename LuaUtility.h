#pragma once

#include "f4se/GameForms.h"
#include "f4se/GameTypes.h"

struct BSFixedStringHash {
	std::size_t operator()(const BSFixedString& str) const noexcept;
};

BGSKeyword* GetKeywordByName(const char* keyword);