#pragma once

namespace RE
{
	class TEXTURE_HAVOK_DATA
	{
	public:
		// members
		std::int8_t friction;     // 0
		std::int8_t restitution;  // 1
	};
	static_assert(sizeof(TEXTURE_HAVOK_DATA) == 0x2);
}
