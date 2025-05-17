#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSPathingDoor;

	class BSNavmeshClosedDoorInfo
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;           // 00
		std::uint16_t                  iriangleIndex;  // 08
	};
	static_assert(sizeof(BSNavmeshClosedDoorInfo) == 0x10);
}
