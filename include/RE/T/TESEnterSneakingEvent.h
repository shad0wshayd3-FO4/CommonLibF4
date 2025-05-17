#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class TESEnterSneakingEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESEnterSneakingEvent>* GetEventSource()
		{
			using func_t = decltype(&TESEnterSneakingEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESEnterSneakingEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESEnterSneakingEvent) == 0x8);
}
