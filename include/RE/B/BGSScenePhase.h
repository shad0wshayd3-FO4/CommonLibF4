#pragma once

#include "RE/T/TESCondition.h"

namespace RE
{
	struct BGSScenePhase
	{
	public:
		// members
		TESCondition  startConditions;       // 00
		TESCondition  completionConditions;  // 08
		std::uint16_t phaseFlags;            // 10
		bool          active;                // 12
		bool          scriptEndRun;          // 13
		bool          runEnd;                // 14
	};
	static_assert(sizeof(BGSScenePhase) == 0x18);
}
