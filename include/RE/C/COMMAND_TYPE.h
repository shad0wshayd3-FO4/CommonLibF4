#pragma once

namespace RE
{
	enum class COMMAND_TYPE
	{
		kNone = 0x0,
		kCall = 0x1,
		kFollow = 0x2,
		kMove = 0x3,
		kAttack = 0x4,
		kInspect = 0x5,
		kRetrieve = 0x6,
		kStay = 0x7,
		kRelease = 0x8,
		kHeal = 0x9,
		kAssign = 0xA,
		kRide = 0xB,
		kEnter = 0xC,
	};
}
