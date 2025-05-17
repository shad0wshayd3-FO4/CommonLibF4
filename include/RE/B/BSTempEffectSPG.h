#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BGSShaderParticleGeometryData;
	class BSGeometry;

	class __declspec(novtable) BSTempEffectSPG :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectSPG };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectSPG };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectSPG };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kSPG };

		~BSTempEffectSPG() override;

		// members
		BGSShaderParticleGeometryData* SPGData;        // 30
		NiPointer<BSGeometry>          geometry;       // 38
		float                          totalFadeTime;  // 40
		float                          fadeTime;       // 44
		bool                           fadeIn;         // 48
	};
	static_assert(sizeof(BSTempEffectSPG) == 0x50);
}
