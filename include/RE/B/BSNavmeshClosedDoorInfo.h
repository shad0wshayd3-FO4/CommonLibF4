#pragma once

namespace RE
{
	struct BSNavmeshClosedDoorInfo
	{
	public:
		// members
		BSTSmartPointer<BSPathingDoor> door;           // 00
		std::uint16_t                  iriangleIndex;  // 08
	};
	static_assert(sizeof(BSNavmeshClosedDoorInfo) == 0x10);
}
