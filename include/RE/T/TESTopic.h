#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/D/DIALOGUE_DATA.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) TESTopic :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTopic };
		static constexpr auto VTABLE{ VTABLE::TESTopic };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDIAL };

		class InfoTree;

		// members
		DIALOGUE_DATA      data;                     // 30
		std::uint32_t      priorityAndJournalIndex;  // 34
		BGSDialogueBranch* ownerBranch;              // 38
		TESQuest*          ownerQuest;               // 40
		BGSKeyword*        subtypeKeyword;           // 48
		TESTopicInfo**     topicInfos;               // 50
		InfoTree*          infoTree;                 // 58
		std::uint32_t      numTopicInfos;            // 60
		std::uint32_t      topicInfoAllocSize;       // 64
		std::uint32_t      firstFileOffset;          // 68
		BSFixedString      formEditorID;             // 70
	};
	static_assert(sizeof(TESTopic) == 0x78);
}
