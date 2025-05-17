#pragma once

#include "RE/B/BGSSceneAction.h"

namespace RE
{
	class __declspec(novtable) BGSSceneActionTimer :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionTimer };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionTimer };

		float seconds;         // 20
		float minSeconds;      // 24
		float timer;           // 28
		bool  scriptEndRun;    // 2C
		bool  runEnd;          // 2D
		float currentSeconds;  // 30
	};
	static_assert(sizeof(BGSSceneActionTimer) == 0x38);
}
