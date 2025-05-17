#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectLoadedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESObjectLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESObjectLoadedEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID formID;  // 00
		bool      loaded;  // 04
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);
}
