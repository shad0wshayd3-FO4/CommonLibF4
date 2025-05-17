#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESLoadGameEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESLoadGameEvent>* GetEventSource()
		{
			using func_t = decltype(&TESLoadGameEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESLoadGameEvent::GetEventSource };
			return func();
		}
	};
	static_assert(sizeof(TESLoadGameEvent) == 0x1);
}
