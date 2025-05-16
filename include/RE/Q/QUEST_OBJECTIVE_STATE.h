#pragma once

namespace RE
{
	enum class QUEST_OBJECTIVE_STATE : std::int32_t
	{
		kDormant = 0x0,
		kDisplayed = 0x1,
		kCompleted = 0x2,
		kCompletedDisplayed = 0x3,
		kFailed = 0x4,
		kFailedDisplayed = 0x5,
	};
}
