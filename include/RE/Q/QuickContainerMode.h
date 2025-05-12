#pragma once

namespace RE
{
	enum class QuickContainerMode : std::int32_t
	{
		kLoot = 0x0,
		kTeammate = 0x1,
		kPowerArmor = 0x2,
		kTurret = 0x3,
		kWorkshop = 0x4,
		kCrafting = 0x5,
		kStealing = 0x6,
		kStealingPowerArmor = 0x7
	};
}
