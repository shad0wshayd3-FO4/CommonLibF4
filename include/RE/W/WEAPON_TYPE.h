#pragma once

namespace RE
{
	enum class WEAPON_TYPE : std::uint8_t
	{
		kNone = 0xFF,
		kHandToHand = 0x0,
		kOneHandSword = 0x1,
		kOneHandDagger = 0x2,
		kOneHandAxe = 0x3,
		kOneHandMace = 0x4,
		kTwoHandSword = 0x5,
		kTwoHandAxe = 0x6,
		kBow = 0x7,
		kStaff = 0x8,
		kGun = 0x9,
		kGrenade = 0xA,
		kMine = 0xB,
	};
}
