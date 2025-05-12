#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSFeaturedItemMessage.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class __declspec(novtable) TESObjectBOOK :
		public TESBoundObject,             // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESIcon,                    // 0B8
		public TESValueForm,               // 0C8
		public TESWeightForm,              // 0D8
		public TESDescription,             // 0E8
		public BGSDestructibleObjectForm,  // 100
		public BGSMessageIcon,             // 110
		public BGSPickupPutdownSounds,     // 128
		public BGSKeywordForm,             // 140
		public BGSFeaturedItemMessage      // 160
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectBOOK };
		static constexpr auto VTABLE{ VTABLE::TESObjectBOOK };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kBOOK };

		// members
		OBJ_BOOK       data;                 // 170
		TESObjectSTAT* inventoryModel;       // 188
		TESDescription itemCardDescription;  // 190
	};
	static_assert(sizeof(TESObjectBOOK) == 0x1A8);
}
