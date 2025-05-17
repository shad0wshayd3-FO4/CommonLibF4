#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSResource_ID.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTempEffect.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiQuaternion.h"

namespace RE
{
	class bhkWorld;
	class PositionPlayerEvent;

	class __declspec(novtable) BSTerrainEffect :
		public BSTempEffect,                      // 00
		public BSTEventSink<PositionPlayerEvent>  // 30
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTerrainEffect };
		static constexpr auto VTABLE{ VTABLE::BSTerrainEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kTerrain };

		class BoneAdjustment
		{
		public:
			// members
			NiMatrix3   rotation;  // 00
			NiAVObject* pBone;     // 30
			float       fZOffset;  // 38
		};
		static_assert(sizeof(BoneAdjustment) == 0x40);

		~BSTerrainEffect() override;

		// members
		NiQuaternion             orientation;         // 38
		NiPoint3                 position;            // 48
		BSTArray<BoneAdjustment> terrainAdjustments;  // 58
		BSTArray<BoneAdjustment> dynamicAdjustments;  // 70
		NiPointer<NiNode>        model;               // 88
		BSResource::ID           modelID;             // 90
		ObjectRefHandle          target;              // 9C
		NiPointer<bhkWorld>      physWorld;           // A0
		std::uint32_t            physGroup;           // A8
		NiPointer<NiAVObject>    followNode;          // B0
	};
	static_assert(sizeof(BSTerrainEffect) == 0xB8);
}
