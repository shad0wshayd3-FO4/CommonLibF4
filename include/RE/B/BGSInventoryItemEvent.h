#pragma once

namespace RE
{
	namespace BGSInventoryItemEvent
	{
		struct Event
		{
			BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>> owner;  // 00
			InventoryInterface::Handle*                                   item;   // 04
		};
	}
}
