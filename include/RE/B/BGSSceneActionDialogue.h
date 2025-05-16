#pragma once

#include "RE/B/BGSSceneAction.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSInputEnableLayer;

	class __declspec(novtable) BGSSceneActionDialogue :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionDialogue };
		static constexpr auto VTABLE{ VTABLE::BGSSceneActionDialogue };

		// members
		TESTopic*                           topic;                 // 20
		float                               maxLoopTime;           // 28
		float                               minLoopTime;           // 2C
		BSTArray<std::uint32_t>             headTrackTargetA;      // 30
		float                               currentLoopTimer;      // 48
		BGSKeyword*                         pAnimFaceArchType;     // 50
		BGSKeyword*                         pSubtypeKeyword;       // 58
		BGSSoundOutput*                     outputModel;           // 60
		BSTSmartPointer<BSInputEnableLayer> pInputLayer;           // 68
		std::uint32_t                       headTargetValue;       // 74
		float                               headTrackChangeTimer;  // 78
	};
	static_assert(sizeof(BGSSceneActionDialogue) == 0x78);
}
