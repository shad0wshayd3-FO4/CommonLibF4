#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESFormDeleteEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESFormDeleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormDeleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESFormDeleteEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID formID;  // 00
	};
	static_assert(sizeof(TESFormDeleteEvent) == 0x04);
}
