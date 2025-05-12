#pragma once

#include "RE/M/MagicItem.h"

namespace RE
{
	class __declspec(novtable) EnchantmentItem :
		public MagicItem  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::EnchantmentItem };
		static constexpr auto VTABLE{ VTABLE::EnchantmentItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kENCH };

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			REX::EnumSet<MagicSystem::CastingType, std::int32_t> castingType;       // 08
			std::int32_t                                         chargeOverride;    // 0C
			REX::EnumSet<MagicSystem::Delivery, std::int32_t>    delivery;          // 10
			REX::EnumSet<MagicSystem::SpellType, std::int32_t>   spellType;         // 14
			float                                                chargeTime;        // 18
			EnchantmentItem*                                     baseEnchantment;   // 20
			BGSListForm*                                         wornRestrictions;  // 28
		};
		static_assert(sizeof(Data) == 0x30);

		// members
		Data data;  // 0D0
	};
	static_assert(sizeof(EnchantmentItem) == 0x100);
}
