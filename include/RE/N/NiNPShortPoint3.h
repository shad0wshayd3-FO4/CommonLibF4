#pragma once

namespace RE
{
	class NiNPShortPoint3
	{
	public:
		// members
		std::int16_t x;  // 0
		std::int16_t y;  // 2
		std::int16_t z;  // 4
	};
	static_assert(sizeof(NiNPShortPoint3) == 0x6);
}
