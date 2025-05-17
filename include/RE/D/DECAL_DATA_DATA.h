#pragma once

namespace RE
{
	class DECAL_DATA_DATA
	{
	public:
		// members
		float         decalMinWidth;   // 00
		float         decalMaxWidth;   // 04
		float         decalMinHeight;  // 08
		float         decalMaxHeight;  // 0C
		float         depth;           // 10
		float         shininess;       // 14
		float         parallaxScale;   // 18
		std::int8_t   parallaxPasses;  // 1C
		std::int8_t   flags;           // 1D
		std::uint32_t color;           // 20
	};
	static_assert(sizeof(DECAL_DATA_DATA) == 0x24);
}
