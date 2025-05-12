#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectREFR;

	struct TESSwitchRaceCompleteEvent
	{
		[[nodiscard]] static BSTEventSource<TESSwitchRaceCompleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSwitchRaceCompleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201874) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESSwitchRaceCompleteEvent) == 0x8);

}
