#pragma once

namespace RE
{
	class BGSDirectionalAmbientLightingColors
	{
	public:
		// members
		std::uint32_t colorValues[7];  // 00
		float         fresnelPower;    // 1C
	};
	static_assert(sizeof(BGSDirectionalAmbientLightingColors) == 0x20);
}
