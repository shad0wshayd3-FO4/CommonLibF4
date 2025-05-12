#pragma once

namespace RE
{
	struct TESEnterSneakingEvent
	{
		[[nodiscard]] static BSTEventSource<TESEnterSneakingEvent>* GetEventSource()
		{
			using func_t = decltype(&TESEnterSneakingEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201837) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESEnterSneakingEvent) == 0x8);
}
