#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class __declspec(novtable) BGSBodyPartData :
		public TESForm,        // 000
		public TESModel,       // 020
		public BGSPreloadable  // 050
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBodyPartData };
		static constexpr auto VTABLE{ VTABLE::BGSBodyPartData };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kBPTD };

		enum PartType
		{
			Torso = 0x0,
			Head1 = 0x1,
			Eye = 0x2,
			LookAt = 0x3,
			FlyGrab = 0x4,
			Head2 = 0x5,
			LeftArm1 = 0x6,
			LeftArm2 = 0x7,
			RightArm1 = 0x8,
			RightArm2 = 0x9,
			LeftLeg1 = 0xA,
			LeftLeg2 = 0xB,
			LeftLeg3 = 0xC,
			RightLeg1 = 0xD,
			RightLeg2 = 0xE,
			RightLeg3 = 0xF,
			Brain = 0x10,
			Weapon = 0x11,
			Root = 0x12,
			COM = 0x13,
			Pelvis = 0x14,
			Camera = 0x15,
			OffsetRoot = 0x16,
			LeftFoot = 0x17,
			RightFoot = 0x18,
			FaceTargetSource = 0x19
		};

		// members
		BGSBodyPart*                     partArray[26];           // 058
		BGSBodyPartDefs::HitReactionData defaultHitReactionData;  // 128
	};
	static_assert(sizeof(BGSBodyPartData) == 0x150);
}
