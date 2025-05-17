#pragma once

#include "RE/R/ReferenceEffect.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"
#include "RE/B/BSTEvent.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BGSArtObjectCloneTask;
	class NiAVObject;
	class BSAnimationGraphEvent;

	class __declspec(novtable) SummonPlacementEffect :
		public ReferenceEffect,                     // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		static constexpr auto RTTI{ RTTI::SummonPlacementEffect };
		static constexpr auto VTABLE{ VTABLE::SummonPlacementEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::SummonPlacementEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kMagicSummon };

		~SummonPlacementEffect() override;

		// members
		BGSArtObject*                    artObject;            // 70
		NiPoint3                         fixedLocation;        // 78
		NiPointer<NiAVObject>            artObject3D;          // 88
		void*                            loadedDataSubBuffer;  // 90
		NiPointer<BGSArtObjectCloneTask> cloneTask;            // 98
		bool                             animationComplete;    // 99
	};
	static_assert(sizeof(SummonPlacementEffect) == 0xA0);
}
