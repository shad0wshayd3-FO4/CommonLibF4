#pragma once

namespace RE
{
	struct PositionPlayerEvent
	{
		enum EVENT_TYPE : std::int32_t
		{
			kPrePositionPlayer = 0x0,
			kPositionPlayerPreUpdatePackages = 0x1,
			kPositionPlayerPostUpdatePackages = 0x2,
			kPostPositionPlayer = 0x3,
			kFinishPositionPlayer = 0x4,
		};

		// members
		EVENT_TYPE type;          // 00
		bool       NoLoadScreen;  // 04
	};
	static_assert(sizeof(PositionPlayerEvent) == 0x8);
}
