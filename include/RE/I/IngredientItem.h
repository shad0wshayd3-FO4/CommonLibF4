#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/M/MagicItem.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class __declspec(novtable) IngredientItem :
		public MagicItem,                  // 000
		public BGSModelMaterialSwap,       // 0D0
		public TESIcon,                    // 110
		public TESWeightForm,              // 120
		public BGSEquipType,               // 130
		public BGSDestructibleObjectForm,  // 140
		public BGSPickupPutdownSounds,     // 150
		public TESValueForm                // 168
	{
	public:
		static constexpr auto RTTI{ RTTI::IngredientItem };
		static constexpr auto VTABLE{ VTABLE::IngredientItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kINGR };

		class GameData
		{
		public:
			// members
			std::uint16_t knownEffectFlags;  // 0
			std::uint16_t playerUses;        // 2
		};
		static_assert(sizeof(GameData) == 0x4);

		// members
		MagicItem::Data data;      // 178
		GameData        gamedata;  // 180
	};
	static_assert(sizeof(IngredientItem) == 0x188);
}
