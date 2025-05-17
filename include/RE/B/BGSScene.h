#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/I/IKeywordFormBase.h"
#include "RE/N/NiTFlags.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSceneAction;
	class BGSScenePhase;

	class __declspec(novtable) BGSScene :
		public TESForm,          // 00
		public IKeywordFormBase  // 20
	{
	public:
		enum class FLAG
		{
			kBeginOnQuestStart = 0x0,
			kStopQuestOnEnd = 0x1,
			kShowAllTextInEditor = 0x2,
			kRepeats = 0x3,
			kInterruptible = 0x4,
			kPlayerDialogue = 0x5,
			kNoPlayerExitDialogue = 0x6,
			kPlayerRadioStation = 0x7,
			kBroadCastScene = 0x8,
			kPauseActorsCurrentSceneinDialogue = 0x9,
			kLookAhead = 0xA,
			kAllowDialogueCamera = 0xB,
			kNoFollowerIdleChatter = 0xC,
		};

		enum class BOOL_BITS
		{
			kActive = 0x1,
			kPhaseActionDone = 0x2,
			KPauseScene = 0x4,
			kSceneScriptFinished = 0x8,
			kNeedsToEnd = 0x10,
			kRandom = 0x20,
			kCombatPause = 0x40,
			kDialoguePause = 0x80,
			kObserveCombatPause = 0x100,
			kPlayerWalkedAway = 0x200,
			kNoUpdate = 0x400,
			kInheritedPhases = 0x800,
			kQueueActive = 0x100000,
			kSceneJumpActive = 0x200000,
			kGamePause = 0x400000,
		};

		static constexpr auto RTTI{ RTTI::BGSScene };
		static constexpr auto VTABLE{ VTABLE::BGSScene };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSCEN };

		// members
		NiTFlags<std::uint32_t, BGSScene> niFlags;                 // 28
		BSTArray<BGSScenePhase*>          phases;                  // 30
		BSTArray<std::uint32_t>           actors;                  // 48
		BSTArray<std::uint32_t>           actorFlags;              // 60
		BSTArray<std::uint32_t>           actorProgressionFlags;   // 78
		BSTArray<BGSSceneAction*>         actions;                 // 90
		TESQuest*                         parentQuest;             // A8
		BGSScene*                         templateScene;           // B0
		std::uint32_t                     flags;                   // B8
		TESCondition                      repeatConditions;        // C0
		std::uint32_t                     speakerID;               // C8
		std::uint32_t                     currentActivePhase;      // CC
		std::uint32_t                     startPhase;              // D0
		float                             randomSceneTimer;        // D4
		float                             maxREFDistanceCenter;    // D8
		ObjectRefHandle                   targetRef;               // DC
		bool                              shouldNotRotateToTrack;  // E0

		void ResetAllSceneActions()
		{
			using func_t = decltype(&BGSScene::ResetAllSceneActions);
			static REL::Relocation<func_t> func{ ID::BGSScene::ResetAllSceneActions };
			return func(this);
		}

		void SetSceneActive(bool abFlag)
		{
			using func_t = decltype(&BGSScene::SetSceneActive);
			static REL::Relocation<func_t> func{ ID::BGSScene::SetSceneActive };
			return func(this, abFlag);
		}
	};
	static_assert(sizeof(BGSScene) == 0xE8);
}
