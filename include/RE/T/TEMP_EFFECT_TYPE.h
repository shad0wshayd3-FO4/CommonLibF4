#pragma once

namespace RE
{
	enum class TEMP_EFFECT_TYPE : std::int32_t
	{
		kTerrain = 0x0,
		kWeaponBlood = 0x1,
		kDecal = 0x2,
		kGeometryDecal = 0x3,
		kParticle = 0x4,
		kDebris = 0x5,
		kSPG = 0x6,
		kDefault = 0x7,
		kRefDefault = 0x8,
		kRefModel = 0x9,
		kRefShader = 0xA,
		kMagicSummon = 0xB
	};
}
