#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"
#include "RE/R/RefAttachTechniqueInput.h"

namespace RE
{
	class BGSArtObjectCloneTask;
	class NiAVObject;
	struct BSAnimationGraphEvent;

	class __declspec(novtable) ModelReferenceEffect :
		public ReferenceEffect,                     // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		static constexpr auto RTTI{ RTTI::ModelReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ModelReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ModelReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefModel };

		~ModelReferenceEffect() override;

		// members
		RefAttachTechniqueInput          hitEffectArtData;     // 70
		void*                            loadedDataSubBuffer;  // B8
		BGSArtObject*                    artObject;            // C0
		NiPointer<BGSArtObjectCloneTask> cloneTask;            // C8
		NiPointer<NiAVObject>            artObject3D;          // D0
		std::uint32_t                    flags;                // D4
	};
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);
}
