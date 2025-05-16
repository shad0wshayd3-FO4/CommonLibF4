#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	namespace InventoryInterface
	{
		struct Handle;
	}

	namespace BGSInventoryItemEvent
	{
		struct Event
		{
			ObjectRefHandle             owner;  // 00
			InventoryInterface::Handle* item;   // 04
		};
	}
}
