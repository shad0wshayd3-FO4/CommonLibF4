#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESFormDeleteEvent
	{
		[[nodiscard]] static BSTEventSource<TESFormDeleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormDeleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201842) };
			return func();
		}

		// members
		TESFormID formID;  // 00
	};
	static_assert(sizeof(TESFormDeleteEvent) == 0x04);

}
