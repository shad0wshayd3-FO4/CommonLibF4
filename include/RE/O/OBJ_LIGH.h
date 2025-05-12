#pragma once

namespace RE
{
	struct OBJ_LIGH
	{
	public:
		// members
		std::int32_t  time;                       // 00
		std::uint32_t radius;                     // 04
		std::uint32_t color;                      // 08
		std::uint32_t flags;                      // 0C
		float         fallOffExponent;            // 10
		float         fov;                        // 14
		float         nearDistance;               // 18
		float         flickerPeriodRecip;         // 1C
		float         flickerIntensityAmplitude;  // 20
		float         flickerMovementAmplitude;   // 24
		float         attenConstant;              // 28
		float         attenScalar;                // 2C
		float         attenExponent;              // 30
		float         godrayNearClipDistance;     // 34
	};
	static_assert(sizeof(OBJ_LIGH) == 0x38);
}
