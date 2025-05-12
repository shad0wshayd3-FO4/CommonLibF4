#pragma once

namespace RE
{
	class __declspec(novtable) TESQuest :
		public BGSStoryManagerTreeForm,  // 000
		public TESFullName               // 028
	{
	public:
		static constexpr auto RTTI{ RTTI::TESQuest };
		static constexpr auto VTABLE{ VTABLE::TESQuest };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kQUST };

		struct AliasesAccess;
		struct ListObjectivesAccess;
		struct ListStagesAccess;

		bool SetStage(std::uint16_t a_stage)
		{
			using func_t = decltype(&TESQuest::SetStage);
			static REL::Relocation<func_t> func{ REL::ID(2207743) };
			return func(this, a_stage);
		}

		BSPointerHandle<TESObjectREFR>* GetAliasedRef(BSPointerHandle<TESObjectREFR>* a_result, std::uint32_t a_aiAliasID)
		{
			using func_t = decltype(&TESQuest::GetAliasedRef);
			static REL::Relocation<func_t> func{ REL::ID(2207810) };
			return func(this, a_result, a_aiAliasID);
		}

		// members
		BSTArray<BGSQuestInstanceText*>                                               instanceData;            // 038
		std::uint32_t                                                                 currentInstanceID;       // 050
		BSTArray<BSTTuple<TESFile*, std::uint32_t>>                                   fileOffsets;             // 058
		BSTArray<BGSBaseAlias*>                                                       aliases;                 // 070
		BSTHashMap<std::uint32_t, BGSLocation*>                                       aliasedLocMap;           // 088
		BSTArray<BSTSmallArray<ObjectRefHandle>>                                      aliasedHandles;          // 0B8
		BSReadWriteLock                                                               aliasAccessLock;         // 0D0
		BGSLocation* nonDormantLocation;      // 0D8
		TESGlobal* questCompleteXPGlobal;   // 0E0
		BSFixedString                                                                 swfFile;                 // 0E8
		QUEST_DATA                                                                    data;                    // 0F0
		std::uint32_t                                                                 eventID;                 // 0F8
		BSTArray<TESQuestStage*>                                                      stages;                  // 100
		BSTArray<BGSQuestObjective*>                                                  objectives;              // 118
		BSTSmallIndexScatterTable<BSTArray<TESQuestStage*>, ListStagesAccess>         stageTable;              // 130
		BSTSmallIndexScatterTable<BSTArray<BGSQuestObjective*>, ListObjectivesAccess> objectiveTable;          // 150
		BSTSmallIndexScatterTable<BSTArray<BGSBaseAlias*>, AliasesAccess>             aliasesTable;            // 170
		TESCondition                                                                  objConditions;           // 190
		TESCondition                                                                  storyManagerConditions;  // 198
		BSTHashMap<BGSDialogueBranch*, BSTArray<TESTopic*>*>                          branchedDialogues[2];    // 1A0
		BSTArray<TESTopic*>                                                           topics[6];               // 200
		BSTArray<BGSScene*>                                                           scenes;                  // 290
		BSTArray<TESGlobal*>* textGlobal;              // 2A8
		std::uint32_t                                                                 totalRefsAliased;        // 2B0
		std::uint16_t                                                                 currentStage;            // 2B4
		bool                                                                          alreadyRun;              // 2B6
		BSStringT<char>                                                               formEditorID;            // 2B8
		const BGSStoryEvent* startEventData;          // 2C8
		NiPointer<QueuedPromoteQuestTask>                                             promoteTask;             // 2D0
		BSTArray<ObjectRefHandle>                                                     promotedRefsArray;       // 2D8
	};
	static_assert(sizeof(TESQuest) == 0x2F0);
}
