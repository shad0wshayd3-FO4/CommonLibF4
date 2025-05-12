#pragma once

namespace RE
{
	struct PACKAGE_DATA
	{
	public:
		// members
		std::uint32_t packFlags;              // 0
		std::int8_t   packType;               // 4
		std::int8_t   interruptOverrideType;  // 5
		std::int8_t   maxSpeed;               // 6
		std::uint16_t foBehaviorFlags;        // 8
		std::uint16_t packageSpecificFlags;   // A
	};
	static_assert(sizeof(PACKAGE_DATA) == 0xC);
}
