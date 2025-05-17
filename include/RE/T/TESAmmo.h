#pragma once

#include "RE/A/AMMO_DATA.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class __declspec(novtable) TESAmmo :
		public TESBoundObject,             // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESIcon,                    // 0B8
		public BGSMessageIcon,             // 0C8
		public TESValueForm,               // 0E0
		public BGSDestructibleObjectForm,  // 0F0
		public BGSPickupPutdownSounds,     // 100
		public TESDescription,             // 118
		public BGSKeywordForm,             // 130
		public TESWeightForm               // 150
	{
	public:
		static constexpr auto RTTI{ RTTI::TESAmmo };
		static constexpr auto VTABLE{ VTABLE::TESAmmo };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kAMMO };

		[[nodiscard]] static bool GetReloadsWithAmmoRef(const TESAmmo* a_ammo)
		{
			using func_t = decltype(&TESAmmo::GetReloadsWithAmmoRef);
			static REL::Relocation<func_t> func{ ID::TESAmmo::GetReloadsWithAmmoRef };
			return func(a_ammo);
		}

		// members
		AMMO_DATA          data;         // 160
		BGSLocalizedString shortDesc;    // 178
		TESModel           shellCasing;  // 180
	};
	static_assert(sizeof(TESAmmo) == 0x1B0);
}
