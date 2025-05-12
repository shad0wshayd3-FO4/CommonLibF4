#pragma once

namespace RE
{
	namespace TESHarvestEvent
	{
		struct ItemHarvested
		{
			[[nodiscard]] static BSTEventSource<ItemHarvested>* GetEventSource()
			{
				using func_t = decltype(&ItemHarvested::GetEventSource);
				static REL::Relocation<func_t> func{ REL::ID(2193351) };
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
