#pragma once

#include "RE/T/TESCondition.h"

namespace RE
{
	class __declspec(novtable) BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneAction };
		static constexpr auto VTABLE{ VTABLE::BGSSceneAction };

		class STARTSCENEACTIONDATA
		{
		public:
			BGSScene*     pScene;
			std::uint16_t sceneStartPhase;
			TESQuest*     parentQuest;
			TESCondition  sceneConditions;
		};

		enum SCENE_ACTION_PLAYER_RESPONSE_TYPE : std::uint32_t
		{
			kPositive = 0x0,
			kNegative = 0x1,
			kNeutral = 0x2,
			kQuestion = 0x3,
			kTotal = 0x4,
			kNone = 0x5
		};

		enum SCENE_ACTION_TYPE : std::uint32_t
		{
			kDialogue = 0x0,
			kPackage = 0x1,
			kTimer = 0x2,
			kPlayerDialogue = 0x3,
			kStartScene = 0x4,
			kNPCResponse = 0x5,
			kRadio = 0x6,
		};

		enum class Flag
		{
			kPlayerUseDialogueSubtypePositive = 1 << 7,
			kPlayerUseDialogueSubtypeNegative = 1 << 8,
			kPlayerUseDialogueSubtypeNeutral = 1 << 9,
			kUseDialogueSubtype = 1 << 10,
			kPlayerUseDialogueSubtypeQuestion = 1 << 11,
			kFaceTaget = 1 << 15,
			kHeadTrackPlayer = 1 << 17,
			kIngoreForCompletion = 1 << 19,
			kCameraSpeakerTarget = 1 << 21
		};

		enum class Status
		{
			kStopped = 0x0,
			kRunning = 0x1,
			kComplete = 0x2
		};

		virtual ~BGSSceneAction();  // 00

		// add
		virtual void              Load(void);                                                           // 01
		virtual void              InitItem(void);                                                       // 02
		virtual void              OnDelete(void);                                                       // 03
		virtual void              ClearData(void);                                                      // 04
		virtual void              Copy(void);                                                           // 05
		virtual bool              QIsLooping(void);                                                     // 06
		virtual bool              QFaceHeadTrackTarget(const BGSScene* scene);                          // 07
		virtual SCENE_ACTION_TYPE GetActionType() const = 0;                                            // 08
		virtual bool              QActionCanEnd();                                                      // 09
		virtual bool              IsPackageActive(BGSScene* scene, TESPackage* package, Actor* actor);  // 0A
		virtual void              LoadGame(void);                                                       // 0B
		virtual void              SaveGame(void);                                                       // 0C
		virtual void              Revert(void);                                                         // 0D
		virtual void              InitLoadGame(void);                                                   // 0E
		virtual void              ResetActionData(void);                                                // 0F
		virtual void              SetInput(void);                                                       // 10
		virtual float             GetActionPercentDone(const BGSScene* scene);                          // 11
		virtual void              StartAction(BGSScene* scene);                                         // 12
		virtual void              EndAction(BGSScene* scene);                                           // 13
		virtual void              CleanUpActionActor(BGSScene* scene);                                  // 14
		virtual void              UpdateAction(BGSScene* scene);                                        // 14

		// members
		std::uint32_t                      actorID;     // 08
		std::uint16_t                      startPhase;  // 0C
		std::uint16_t                      endPhase;    // 0E
		REX::EnumSet<Flag, std::uint32_t>  flags;       // 10
		REX::EnumSet<Status, std::uint8_t> status;      // 14
		std::uint32_t                      uniqueID;    // 18
	};
	static_assert(sizeof(BGSSceneAction) == 0x20);
}
