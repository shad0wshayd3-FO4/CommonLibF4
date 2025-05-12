#pragma once

namespace RE
{
	struct SCRIPT_EFFECT_DATA
	{
	public:
		// members
		bool  scriptEffectStart;   // 0
		bool  scriptEffectFinish;  // 1
		float secondsElapsed;      // 4
	};
	static_assert(sizeof(SCRIPT_EFFECT_DATA) == 0x8);
}
