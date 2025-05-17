#pragma once

#include "RE/B/BGSStoryManagerNodeBase.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class __declspec(novtable) BGSStoryManagerQuestNode :
		public BGSStoryManagerNodeBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSStoryManagerQuestNode };
		static constexpr auto VTABLE{ VTABLE::BGSStoryManagerQuestNode };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSMQN };

		// members
		BSTArray<TESQuest*>                  children;                 // 48
		BSTHashMap<TESQuest*, std::uint32_t> perQuestFlags;            // 60
		BSTHashMap<TESQuest*, float>         perQuestHoursUntilReset;  // 90
		std::uint32_t                        numQuestsToStart;         // C0
		BSTArray<float>                      childrenLastRun;          // C8
	};
	static_assert(sizeof(BGSStoryManagerQuestNode) == 0xE0);
}
