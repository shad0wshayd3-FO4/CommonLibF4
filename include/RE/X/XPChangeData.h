#pragma once

namespace RE
{
	struct XPChangeData
	{
	public:
		// members
		std::uint32_t playerLevel;              // 00
		float         initialExperiencePoints;  // 04
		float         experiencePointsAdded;    // 08
		bool          syncedXP;                 // 0C
	};
	static_assert(sizeof(XPChangeData) == 0x10);
}
