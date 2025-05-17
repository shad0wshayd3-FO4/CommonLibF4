#pragma once

namespace RE
{
	class INTERIOR_DATA
	{
	public:
		// members
		std::uint32_t                       ambient;                           // 00
		std::uint32_t                       directional;                       // 04
		std::uint32_t                       fogColorNear;                      // 08
		float                               fogNear;                           // 0C
		float                               fogFar;                            // 10
		std::uint32_t                       directionalXY;                     // 14
		std::uint32_t                       directionalZ;                      // 18
		float                               directionalFade;                   // 1C
		float                               clipDist;                          // 20
		float                               fogPower;                          // 24
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // 28
		std::uint32_t                       fogColorFar;                       // 48
		float                               fogClamp;                          // 4C
		float                               lightFadeStart;                    // 50
		float                               lightFadeEnd;                      // 54
		std::uint32_t                       lightingTemplateInheritanceFlags;  // 58
		float                               fogHeightMid;                      // 5C
		float                               fogHeightRange;                    // 60
		std::uint32_t                       fogColorHighNear;                  // 64
		std::uint32_t                       fogColorHighFar;                   // 68
		float                               fogHighDensityScale;               // 6C
		float                               fogNearColorScale;                 // 70
		float                               fogFarColorScale;                  // 74
		float                               fogHighNearColorScale;             // 78
		float                               fogHighFarColorScale;              // 7C
		float                               fogFarHeightMid;                   // 80
		float                               fogFarHeightRange;                 // 84
		std::uint32_t                       interiorOffset;                    // 88
	};
	static_assert(sizeof(INTERIOR_DATA) == 0x8C);
}
