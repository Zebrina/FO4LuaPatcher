#include "f4se_common/f4se_version.h"
#include "f4se/PluginAPI.h"
#include "f4se/GameAPI.h"

#include "LuaScriptProcessor.h"

IDebugLog gLog("LuaPatcher.log");
//IDebugLog gLog("Data\\F4SE\\Plugins\\LuaPatcher.log");

struct {
	PluginHandle pluginHandle = kPluginHandle_Invalid;
	F4SEMessagingInterface* messaging = nullptr;
} global;

void HandleF4SEMessage(F4SEMessagingInterface::Message* msg) {
	switch (msg->type) {
	case F4SEMessagingInterface::kMessage_GameDataReady:
		ProcessLuaScripts();
		break;
	}
}

/* Plugin Query */

extern "C" {
	bool F4SEPlugin_Query(const F4SEInterface* f4se, PluginInfo* info) {
		//_MESSAGE("F4SEPlugin_Query begin");

		// populate info structure
		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = "Fallout 4 Lua Patcher";
		info->version = 1;

		// store plugin handle so we can identify ourselves later
		global.pluginHandle = f4se->GetPluginHandle();

		if (f4se->isEditor) {
			_MESSAGE("\tloaded in editor, marking as incompatible");

			return false;
		}
		else if (f4se->runtimeVersion != RUNTIME_VERSION_1_10_64) {
			_MESSAGE("\tunsupported runtime version %08X", f4se->runtimeVersion);

			return false;
		}

		global.messaging = (F4SEMessagingInterface*)f4se->QueryInterface(kInterface_Messaging);
		if (!global.messaging) {
			_MESSAGE("\tcouldn't get messaging interface");
			return false;
		}
		if (global.messaging->interfaceVersion < F4SEMessagingInterface::kInterfaceVersion) {
			_MESSAGE("\tmessaging interface too old (%d expected %d)", global.messaging->interfaceVersion, F4SEMessagingInterface::kInterfaceVersion);
			return false;
		}

		// ### do not do anything else in this callback
		// ### only fill out PluginInfo and return true/false

		//_MESSAGE("F4SEPlugin_Query end");

		// supported runtime version
		return true;
	}

	bool F4SEPlugin_Load(const F4SEInterface * f4se) {
		//_MESSAGE("F4SEPlugin_Load begin");

		global.messaging->RegisterListener(global.pluginHandle, "F4SE", HandleF4SEMessage);

		//_MESSAGE("F4SEPlugin_Load end");

		return true;
	}

};
