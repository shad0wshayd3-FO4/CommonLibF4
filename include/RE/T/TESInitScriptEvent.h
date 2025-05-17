#pragma once

namespace RE
{
	class TESInitScriptEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESInitScriptEvent>* GetEventSource()
		{
			using func_t = decltype(&TESInitScriptEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2691330) };
			return func();
		}

		// members
		TESObjectREFR* hObjectInitialized;  // 00
	};
	static_assert(sizeof(TESInitScriptEvent) == 0x8);
}
