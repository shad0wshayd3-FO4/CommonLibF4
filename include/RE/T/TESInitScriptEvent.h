#pragma once

namespace RE
{
	class TESInitScriptEvent
	{
	public:
		// Members
		TESObjectREFR* hObjectInitialized;  // 00
	};
	static_assert(sizeof(TESInitScriptEvent) == 0x8);
}
