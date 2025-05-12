#pragma once

namespace RE
{
	class AITimer
	{
	public:
		float startTime;   // 0
		float targetTime;  // 4
	};
	static_assert(sizeof(AITimer) == 0x8);
}
