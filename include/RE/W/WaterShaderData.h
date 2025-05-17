#pragma once

namespace RE
{
	class WaterShaderData
	{
	public:
		// members
		float         maxDepth;                // 00
		std::uint32_t shallowWaterColor;       // 04
		std::uint32_t deepWaterColor;          // 08
		float         shallowFogColorRange;    // 0C
		float         deepFogColorRange;       // 10
		float         shallowAlpha;            // 14
		float         deepAlpha;               // 18
		float         shallowFogAlphaRange;    // 1C
		float         deepFogAlphaRange;       // 20
		std::uint32_t underwaterFogColor;      // 24
		float         underwaterFogAmount;     // 28
		float         underwaterFogDistNear;   // 2C
		float         underwaterFogDistFar;    // 30
		float         normalMagnitude;         // 34
		float         normalFalloffShallow;    // 38
		float         normalFalloffDeep;       // 3C
		float         reflectionAmount;        // 40
		float         fresnelAmount;           // 44
		float         surfaceEffectFalloff;    // 48
		float         displacementForce;       // 4C
		float         displacementVelocity;    // 50
		float         displacementFalloff;     // 54
		float         displacementDampener;    // 58
		float         displacementSize;        // 5C
		std::uint32_t reflectionWaterColor;    // 60
		float         sunSpecularPower;        // 64
		float         sunSpecularMagnitude;    // 68
		float         sunSparklePower;         // 6C
		float         sunSparkleMagnitude;     // 70
		float         lightRadius;             // 74
		float         lightBrightness;         // 78
		float         shininess;               // 7C
		float         noiseWindDirections[3];  // 80
		float         noiseWindSpeeds[3];      // 8C
		float         amplitude[3];            // 98
		float         uvScales[3];             // A4
		float         noiseFalloff[3];         // B0
		float         siltAmount;              // BC
		std::uint32_t lightSiltColor;          // C0
		std::uint32_t darkSiltColor;           // C4
		bool          ssrEnabled;              // C8
	};
	static_assert(sizeof(WaterShaderData) == 0xCC);
}
