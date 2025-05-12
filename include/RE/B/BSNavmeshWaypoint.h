#pragma once

namespace RE
{
	struct BSNavmeshWaypoint
	{
	public:
		// members
		NiPoint3      position;       // 00
		std::uint16_t triangleIndex;  // 0C
		std::uint32_t flags;          // 10
	};
	static_assert(sizeof(BSNavmeshWaypoint) == 0x14);
}
