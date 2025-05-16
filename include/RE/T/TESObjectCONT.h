#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicCasterForm.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESWeightForm.h"
#include "RE/C/CONT_DATA.h"

namespace RE
{
	class __declspec(novtable) TESObjectCONT :
		public TESBoundAnimObject,         // 000
		public TESContainer,               // 068
		public TESFullName,                // 080
		public BGSModelMaterialSwap,       // 090
		public TESWeightForm,              // 0D0
		public TESMagicCasterForm,         // 148
		public TESMagicTargetForm,         // 148
		public BGSDestructibleObjectForm,  // 0E0
		public BGSOpenCloseForm,           // 0F0
		public BGSKeywordForm,             // 0F8
		public BGSForcedLocRefType,        // 118
		public BGSPropertySheet,           // 128
		public BGSNativeTerminalForm       // 138
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectCONT };
		static constexpr auto VTABLE{ VTABLE::TESObjectCONT };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCONT };

		enum class Flags : std::int8_t
		{
			kRespawn = 0x2,
			kShowOwner = 0x4
		};

		// members
		CONT_DATA               data;              // 149
		BGSSoundDescriptorForm* openSound;         // 150
		BGSSoundDescriptorForm* closeSound;        // 158
		BGSSoundDescriptorForm* takeAllSound;      // 160
		BGSListForm*            containsOnlyList;  // 168
	};
	static_assert(sizeof(TESObjectCONT) == 0x170);
}
