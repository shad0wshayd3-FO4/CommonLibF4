#pragma once

namespace RE
{
	enum class FIGHT_REACTION : std::int32_t
	{
		kNeutral = 0x0,
		kEnemy = 0x1,
		kAlly = 0x2,
		kFriend = 0x3
	};
}
