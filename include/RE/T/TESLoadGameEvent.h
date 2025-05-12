#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESLoadGameEvent
	{
		[[nodiscard]] static BSTEventSource<TESLoadGameEvent>* GetEventSource()
		{
			using func_t = decltype(&TESLoadGameEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201848) };
			return func();
		}
	};
	static_assert(sizeof(TESLoadGameEvent) == 0x1);
}
