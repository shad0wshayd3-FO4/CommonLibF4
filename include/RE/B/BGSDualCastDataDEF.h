#pragma once

namespace RE
{
	class BGSDualCastDataDEF
	{
	public:
		// members
		BGSProjectile*    projectile;     // 00
		BGSExplosion*     explosion;      // 08
		TESEffectShader*  effectShader;   // 10
		BGSArtObject*     hitEffectArt;   // 18
		BGSImpactDataSet* impactDataSet;  // 20
		std::uint32_t     flags;          // 28
	};
	static_assert(sizeof(BGSDualCastDataDEF) == 0x30);
}
