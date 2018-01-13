#pragma once

class Lua;

bool RunLuaFile(Lua* lua, const char* file);

void ProcessLuaScripts();