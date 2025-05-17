#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	namespace TESHarvestEvent
	{
		class ItemHarvested
		{
		public:
			[[nodiscard]] static BSTEventSource<ItemHarvested>* GetEventSource()
			{
				using func_t = decltype(&ItemHarvested::GetEventSource);
				static REL::Relocation<func_t> func{ ID::TESHarvestEvent::GetEventSource };
				return func();
			}

			// members
			const TESBoundObject* itemHarvested;       // 00
			TESObjectREFR*        referenceHarvested;  // 08
			const Actor*          harvestedBy;         // 10
		};
		static_assert(sizeof(ItemHarvested) == 0x18);
	}
}
