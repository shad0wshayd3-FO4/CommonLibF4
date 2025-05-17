#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	namespace InventoryInterface
	{
		class Handle;
	}

	namespace BGSInventoryItemEvent
	{
		class Event
		{
		public:
			ObjectRefHandle             owner;  // 00
			InventoryInterface::Handle* item;   // 04
		};
	}
}
