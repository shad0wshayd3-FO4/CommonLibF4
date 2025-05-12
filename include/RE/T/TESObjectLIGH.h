#pragma once

#include "RE/T/TESBoundAnimObject.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESIcon.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/T/TESWeightForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSKeywordForm.h"

namespace RE
{
	class __declspec(novtable) TESObjectLIGH :
		public TESBoundAnimObject,         // 000
		public BGSModelMaterialSwap,       // 068
		public TESIcon,                    // 0A8
		public BGSMessageIcon,             // 0B8
		public TESWeightForm,              // 0D0
		public TESValueForm,               // 0E0
		public BGSDestructibleObjectForm,  // 0F0
		public BGSEquipType,               // 100
		public BGSPropertySheet,           // 110
		public BGSOpenCloseForm,           // 120
		public BGSKeywordForm              // 128
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectLIGH };
		static constexpr auto VTABLE{ VTABLE::TESObjectLIGH };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLIGH };

		// members
		OBJ_LIGH                data;            // 148
		float                   fade;            // 180
		BGSSoundDescriptorForm* sound;           // 188
		TESTexture              goboTexture;     // 190
		NiColor                 emittanceColor;  // 1A0
		BGSLensFlare*           lensFlare;       // 1B0
		BGSGodRays*             godRays;         // 1B8
	};
	static_assert(sizeof(TESObjectLIGH) == 0x1C0);
}
