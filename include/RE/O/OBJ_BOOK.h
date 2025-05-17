#pragma once

namespace RE
{
	class OBJ_BOOK
	{
	public:
		union Teaches
		{
			ActorValueInfo* actorValueToAdvance;
			SpellItem*      spell;
			BGSPerk*        perk;
		};
		static_assert(sizeof(Teaches) == 0x8);

		// members
		std::int8_t   flags;        // 00
		Teaches       teaches;      // 08
		std::uint32_t textOffsetX;  // 10
		std::uint32_t textOffsetY;  // 14
	};
	static_assert(sizeof(OBJ_BOOK) == 0x18);
}
