#pragma once

namespace RE
{
	struct PART_DATA
	{
	public:
		// members
		float             damageMult;                    // 00
		BGSDebris*        explosionGenericDebris;        // 08
		BGSExplosion*     explosion;                     // 10
		float             explosionGenericDebrisScale;   // 18
		BGSDebris*        dismemberGenericDebris;        // 20
		BGSExplosion*     dismemberExplosion;            // 28
		float             dismemberGenericDebrisScale;   // 30
		BGSDebris*        onCrippleGenericDebris;        // 38
		BGSExplosion*     onCrippleExplosion;            // 40
		float             onCrippleGenericDebrisScale;   // 48
		NiPoint3          goreTranslate;                 // 4C
		NiPoint3          goreRotate;                    // 58
		BGSImpactDataSet* dismemberImpactDataSet;        // 68
		BGSImpactDataSet* explosionImpactDataSet;        // 70
		BGSImpactDataSet* onCrippleImpactDataSet;        // 78
		ActorValueInfo*   actorValue;                    // 80
		BGSArtObject*     artObject;                     // 88
		float             explosionSpecialDebrisScale;   // 90
		std::uint8_t      flags;                         // 94
		std::uint8_t      type;                          // 95
		std::uint8_t      healthPercent;                 // 96
		std::uint8_t      toHitChance;                   // 97
		std::uint8_t      explosionChance;               // 98
		std::uint8_t      nonLethalDismembermentChance;  // 99
		std::uint8_t      dismemberGenericDebrisCount;   // 9A
		std::uint8_t      onCrippleGenericDebrisCount;   // 9B
		std::uint8_t      explosionGenericDebrisCount;   // 9C
		std::uint8_t      dismemberDecalCount;           // 9D
		std::uint8_t      onCrippleDecalCount;           // 9E
		std::uint8_t      explosionDecalCount;           // 9F
		std::uint8_t      geometrySegmentIndex;          // A0
	};
	static_assert(sizeof(PART_DATA) == 0xA8);
}
