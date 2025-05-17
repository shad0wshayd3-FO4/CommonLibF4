#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class TESObjectREFR;

	class TESSwitchRaceCompleteEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESSwitchRaceCompleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSwitchRaceCompleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESSwitchRaceCompleteEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESSwitchRaceCompleteEvent) == 0x8);
}
