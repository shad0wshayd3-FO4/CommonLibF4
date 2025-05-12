#pragma once

namespace RE
{
	class CachedValues
	{
	public:
		// members
		float                     cachedRadius;              // 00
		float                     cachedWidth;               // 04
		float                     cachedLength;              // 08
		float                     cachedForwardLength;       // 0C
		float                     cachedDPS;                 // 10
		float                     cachedEyeLevel;            // 14
		float                     cachedWalkSpeed;           // 18
		float                     cachedRunSpeed;            // 1C
		float                     cachedJogSpeed;            // 20
		float                     cachedFastWalkSpeed;       // 24
		std::uint32_t             booleanValues;             // 28
		std::uint32_t             flags;                     // 2C
		BSTArray<CachedValueData> actorValueCache;           // 30
		BSTArray<CachedValueData> permanentActorValueCache;  // 48
	};
	static_assert(sizeof(CachedValues) == 0x60);
}
