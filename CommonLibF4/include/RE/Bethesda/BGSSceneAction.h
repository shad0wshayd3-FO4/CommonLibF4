#pragma once

#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/TESCondition.h"
#include "RE/Bethesda/TESForms.h"

namespace RE
{
	class Actor;
	class BGSScene;
	class BGSKeyword;
	class BGSSoundDescriptorForm;
	class BGSSoundOutput;
	class BSInputEnableLayer;
	class TESCondition;
	class TESPackage;
	class TESQuest;
	class TESTopic;

	class __declspec(novtable) BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneAction };
		static constexpr auto VTABLE{ VTABLE::BGSSceneAction };

		struct STARTSCENEACTIONDATA
		{
			BGSScene*     pScene;
			std::uint16_t sceneStartPhase;
			TESQuest*     parentQuest;
			TESCondition  sceneConditions;
		};

		enum SCENE_ACTION_PLAYER_RESPONSE_TYPE : std::uint32_t
		{
			kPositive = 0,
			kNegative = 1,
			kNeutral = 2,
			kQuestion = 3,
			kTotal = 4,
			kNone
		};

		enum SCENE_ACTION_TYPE : std::uint32_t
		{
			kDialogue = 0,
			kPackage = 1,
			kTimer = 2,
			kPlayerDialogue = 3,
			kStartScene = 4,
			kNPCResponse = 5,
			kRadio = 6,
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
			kStopped,
			kRunning,
			kComplete
		};

		virtual ~BGSSceneAction();  // 00

		// add
		virtual void              Load(void);                                                           // 01
		virtual void              InitItem(void);                                                       // 02
		virtual void              OnDelete(void);                                                       // 03
		virtual void              ClearData(void);                                                      // 04
		virtual void              Copy(void);															// 05
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

	class __declspec(novtable) BGSSceneActionConversationBase :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionConversationBase };
		static constexpr auto VTABLE{ VTABLE::BGSSceneActionConversationBase };

		TESTopic*               responseTopics[4];            // 20
		BGSKeyword*             pResponseSubtypeKeywords[4];  // 40
		BGSSoundOutput*         pOutputModel;                 // 60
		BSTArray<std::uint32_t> headTrackTargetA;             // 68
		std::uint32_t           headTargetValue;              // 80
		float                   headTrackChangeTimer;         // 84
		TESTopic*               currentTopic;                 // 88
	};
	static_assert(sizeof(BGSSceneActionConversationBase) == 0x90);

	class __declspec(novtable) BGSSceneActionPlayerDialogue :
		public BGSSceneActionConversationBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionPlayerDialogue };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionPlayerDialogue };

		std::uint64_t                     dialogueTarget;                  // 90
		TESTopic*                         pNPCResponseTopics[4];           // 98
		BGSKeyword*                       pNPCResponseSubtypeKeywords[4];  // B8
		TESTopic*                         pTopic;                          // D8
		std::uint32_t					  playerInput;                     // E0

		TESTopicInfo* GetCurrentTopicInfo(BGSScene* a_parentScene, TESObjectREFR* a_target, std::uint32_t a_type)
		{
			using func_t = decltype(&BGSSceneActionPlayerDialogue::GetCurrentTopicInfo);
			static REL::Relocation<func_t> func{ REL::ID(2196825) };
			return func(this, a_parentScene, a_target, a_type);
		}
	};
	static_assert(sizeof(BGSSceneActionPlayerDialogue) == 0xE8);

	class __declspec(novtable) BGSSceneActionNPCResponseDialogue :
		public BGSSceneActionConversationBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionNPCResponseDialogue };
		static constexpr auto VTABLE{ VTABLE::BGSSceneActionNPCResponseDialogue };

		TESTopicInfo* GetCurrentTopicInfo(BGSScene* a_parentScene)
		{
			using func_t = decltype(&BGSSceneActionNPCResponseDialogue::GetCurrentTopicInfo);
			static REL::Relocation<func_t> func{ REL::ID(2196825) };
			return func(this, a_parentScene);
		}
	};
	static_assert(sizeof(BGSSceneActionNPCResponseDialogue) == 0x90);

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

	class __declspec(novtable) BGSSceneActionRadio :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionRadio };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionRadio };

		TESTopic*               topic;           // 20
		BGSSoundDescriptorForm* sound;           // 28
		BGSSoundOutput*         outputModel;     // 30
		BGSKeyword*             subtypeKeyword;  // 38
		BGSSoundDescriptorForm* topicSound;      // 40
		float                   soundDuration;   // 48
		std::uint32_t           soundID;         // 4C
		bool                    soundDone;       // 50
		TESTopic*               currentTopic;    // 58
		float                   failTimer;       // 60
	};
	static_assert(sizeof(BGSSceneActionRadio) == 0x68);

	class __declspec(novtable) BGSSceneActionPackage :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionPackage };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionPackage };

		std::uint32_t         currentPackIndex;  // 20
		BSTArray<TESPackage*> packages;          // 28
	};
	static_assert(sizeof(BGSSceneActionPackage) == 0x40);
}
