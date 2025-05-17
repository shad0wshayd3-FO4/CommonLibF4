#pragma once

#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/M/MagicItem.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class __declspec(novtable) AlchemyItem :
		public MagicItem,                  // 000
		public BGSModelMaterialSwap,       // 0D0
		public TESIcon,                    // 110
		public BGSMessageIcon,             // 120
		public TESWeightForm,              // 138
		public BGSEquipType,               // 148
		public BGSDestructibleObjectForm,  // 158
		public BGSPickupPutdownSounds,     // 168
		public BGSCraftingUseSound,        // 180
		public TESDescription              // 190
	{
	public:
		static constexpr auto RTTI{ RTTI::AlchemyItem };
		static constexpr auto VTABLE{ VTABLE::AlchemyItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kALCH };

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			SpellItem*              addictionItem;     // 08
			float                   addictionChance;   // 10
			BGSSoundDescriptorForm* consumptionSound;  // 18
			BGSLocalizedString      addictionName;     // 20
		};
		static_assert(sizeof(Data) == 0x28);

		// members
		Data    data;         // 1A8
		TESIcon messageIcon;  // 1D0
	};
	static_assert(sizeof(AlchemyItem) == 0x1E0);
}
