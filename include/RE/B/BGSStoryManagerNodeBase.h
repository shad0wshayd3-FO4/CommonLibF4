#pragma once

#include "RE/B/BGSStoryManagerTreeForm.h"

namespace RE
{
	class __declspec(novtable) BGSStoryManagerNodeBase :
		public BGSStoryManagerTreeForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSStoryManagerNodeBase };
		static constexpr auto VTABLE{ VTABLE::BGSStoryManagerNodeBase };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		// add
		virtual std::uint32_t GetQuestsStarted() const = 0;  // 4E

		// members
		BGSStoryManagerBranchNode* parent;       // 28
		BGSStoryManagerNodeBase*   prevSibling;  // 30
		std::uint32_t              maxQuests;    // 38
		std::uint32_t              flags;        // 3C
		TESCondition               conditions;   // 40
	};
	static_assert(sizeof(BGSStoryManagerNodeBase) == 0x48);
}
