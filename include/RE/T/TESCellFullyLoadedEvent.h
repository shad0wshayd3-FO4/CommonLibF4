#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESCellFullyLoadedEvent
	{
		[[nodiscard]] static BSTEventSource<TESCellFullyLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellFullyLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201824) };
			return func();
		}

		// members
		TESObjectCELL* cell;
	};
	static_assert(sizeof(TESCellFullyLoadedEvent) == 0x8);
}
