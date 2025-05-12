#pragma once

namespace RE
{
	struct AttackData
	{
	public:
		// members
		float         damageMult;        // 00
		float         attackChance;      // 04
		SpellItem*    attackSpell;       // 08
		std::uint32_t flags;             // 10
		float         attackAngle;       // 14
		float         strikeAngle;       // 18
		std::int32_t  staggerOffset;     // 1C
		BGSKeyword*   attackType;        // 20
		float         knockdown;         // 28
		float         recoveryTime;      // 2C
		float         actionPointsMult;  // 30
	};
	static_assert(sizeof(AttackData) == 0x38);
}
