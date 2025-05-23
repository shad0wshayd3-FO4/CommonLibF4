#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESContainerChangedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESContainerChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESContainerChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESContainerChangedEvent::GetEventSource };
			return func();
		}

		// members
		std::uint32_t oldContainerFormID;  // 00
		std::uint32_t newContainerFormID;  // 04
		std::uint32_t baseObjectFormID;    // 08
		std::int32_t  itemCount;           // 0C
		std::uint32_t referenceFormID;     // 10
		std::uint16_t uniqueID;            // 14
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x18);
}
