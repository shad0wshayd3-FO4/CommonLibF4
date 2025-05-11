#pragma once

namespace RE
{
	enum class POWER_ARMOR_HUD_VISIBILITY_RULE
	{
		kIgnoresPAHUDVisibility = 0x0,
		kOnlyWithPAHUDVisible = 0x1,
		kOnlyWithPAHUDNotVisible = 0x2
	};

	class HUDModeType;

	class HUDModes
	{
	public:
		// members
		BSTArray<HUDModeType>                                        validHUDModes;                // 00
		REX::EnumSet<POWER_ARMOR_HUD_VISIBILITY_RULE, std::uint32_t> powerArmorHUDVisibilityRule;  // 18
		bool                                                         canBeVisible;                 // 1C
	};
	static_assert(sizeof(HUDModes) == 0x20);
}
