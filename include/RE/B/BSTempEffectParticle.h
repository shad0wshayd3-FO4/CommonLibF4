#pragma once

namespace RE
{
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
		BSModelDB::Handle                     modelHandle;      // 40
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
