#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTempEffect.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class BGSDecalEmitter;
	class BGSParticleObjectCloneTask;
	class NiNode;

	class __declspec(novtable) BSTempEffectParticle :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectParticle };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectParticle };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectParticle };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kParticle };

		~BSTempEffectParticle() override;

		// members
		NiPointer<NiAVObject>                 particleObject;   // 30
		NiPointer<BGSParticleObjectCloneTask> cloneTask;        // 38
		void*                                 modelHandle;      // 40 - BSModelDB::Handle
		NiPointer<NiNode>                     parentNode;       // 48
		NiMatrix3                             rotation;         // 50
		NiPoint3                              position;         // 80
		float                                 scale;            // 8C
		std::uint32_t                         flags;            // 90
		NiPointer<NiAVObject>                 followObject;     // 98
		NiTransform                           followOffset;     // A0
		BGSImpactData*                        decalImpactData;  // E0
		BGSDecalEmitter*                      decalEmitter;     // E8
		BSSoundHandle                         sound1;           // F0
		BSSoundHandle                         sound2;           // F8
	};
	static_assert(sizeof(BSTempEffectParticle) == 0x100);
}
