#pragma once

namespace RE
{
	class __declspec(novtable) SpellItem :
		public MagicItem,             // 000
		public BGSEquipType,          // 0D0
		public BGSMenuDisplayObject,  // 0E0
		public TESDescription         // 0F0
	{
	public:
		static constexpr auto RTTI{ RTTI::SpellItem };
		static constexpr auto VTABLE{ VTABLE::SpellItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSPEL };

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			REX::EnumSet<MagicSystem::SpellType, std::int32_t>   spellType;     // 08
			float                                                chargeTime;    // 0C
			REX::EnumSet<MagicSystem::CastingType, std::int32_t> castingType;   // 10
			REX::EnumSet<MagicSystem::Delivery, std::int32_t>    delivery;      // 14
			float                                                castDuration;  // 18
			float                                                range;         // 1C
			BGSPerk* castingPerk;   // 20
		};
		static_assert(sizeof(Data) == 0x28);

		// members
		Data data;  // 108
	};
	static_assert(sizeof(SpellItem) == 0x130);
}
