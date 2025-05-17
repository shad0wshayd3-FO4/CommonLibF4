#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSQuestInstanceText
	{
	public:
		class StringData
		{
		public:
			// members
			std::uint32_t aliasID;         // 00
			std::uint32_t fullNameFormID;  // 04
		};
		static_assert(sizeof(StringData) == 0x8);

		class GlobabValueData
		{
		public:
			// members
			const TESGlobal* global;  // 00
			float            value;   // 08
		};
		static_assert(sizeof(GlobabValueData) == 0x10);

		static void ParseString(BSString* a_inOutText, const TESQuest* a_quest, std::uint32_t a_instanceID)
		{
			using func_t = decltype(&BGSQuestInstanceText::ParseString);
			static REL::Relocation<func_t> func{ ID::BGSQuestInstanceText::ParseString };
			return func(a_inOutText, a_quest, a_instanceID);
		}

		// Members
		std::uint32_t             id;                // 00
		BSTArray<StringData>      stringData;        // 08
		BSTArray<GlobabValueData> valueData;         // 20
		std::uint16_t             journalStage;      // 38
		std::uint16_t             journalStageItem;  // 3A
	};
	static_assert(sizeof(BGSQuestInstanceText) == 0x40);
}
