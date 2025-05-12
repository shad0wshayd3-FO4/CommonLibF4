#pragma once

#include "RE/B/BGSSceneAction.h"

namespace RE
{
	class __declspec(novtable) BGSSceneActionStartScene :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionStartScene };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionStartScene };

		BSTArray<STARTSCENEACTIONDATA*> scenesA;              // 20
		BGSScene*                       scene;                // 38
		std::uint16_t                   sceneStartPhase;      // 40
		bool                            endSceneSayGreeting;  // 42
	};
	static_assert(sizeof(BGSSceneActionStartScene) == 0x48);
}
