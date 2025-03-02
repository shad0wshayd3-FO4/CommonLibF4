#pragma once

namespace RE
{
	class hkAabb16
	{
	public:
		// members
		std::uint16_t min[3];
		std::uint16_t key;
		std::uint16_t max[3];
		std::uint16_t key1;
	};
	static_assert(sizeof(hkAabb16) == 0x10);
}
