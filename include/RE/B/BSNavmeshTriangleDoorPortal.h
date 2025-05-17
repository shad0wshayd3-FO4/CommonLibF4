#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSPathingDoor;

	struct BSNavmeshTriangleDoorPortal
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;                 // 00
		std::uint16_t                  owningTriangleIndex;  // 08
	};
	static_assert(sizeof(BSNavmeshTriangleDoorPortal) == 0x10);
}
