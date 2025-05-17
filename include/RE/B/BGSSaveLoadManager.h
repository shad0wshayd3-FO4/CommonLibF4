#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSSaveDataSystemUtility.h"
#include "RE/B/BSSaveDataSystemUtilityImage.h"
#include "RE/B/BGSSaveLoadThread.h"

namespace RE
{
	class BSSaveDataSystemUtilityFile;
	class BGSSaveLoadFile;
	class BGSSaveLoadFileEntry;
	class NiTexture;

	namespace SPECIALMenuEvent
	{
		class NameChangedEvent;
	}

	class BGSSaveLoadManager :
		public BSTEventSink<SPECIALMenuEvent::NameChangedEvent>  // 00
	{
	public:
		using SaveCompleteCallback_t = void (*)(BSSaveDataSystemUtility::RESULT, BSSaveDataSystemUtilityFile**);
		using LoadCompleteCallback_t = void (*)(BSSaveDataSystemUtility::RESULT, BSSaveDataSystemUtilityFile**);

		enum class QUEUED_TASK : std::int32_t
		{
			kAutoSave = 0x1,
			kForceSave = 0x2,
			kLoadMostRecentSave = 0x4,
			kQuickSave = 0x8,
			kQuickLoad = 0x10,
			kQuickNewSave = 0x20,
			kLoadGame = 0x40,
			kSysUtilLoadGame = 0x80,
			kMissingContentLoad = 0x100,
			kAutoSaveCommit = 0x200,
			kQuickSaveCommit = 0x400,
			kCaptureFaceGen = 0x800,
			kBuildSaveGameList = 0x1000,
			kRefreshScreenshot = 0x2000,
			kSaveAndQuit = 0x4000,
			kConfirmModsLoad = 0x8000,
			kSaveAndQuitToDesktop = 0x10000,
		};

		virtual ~BGSSaveLoadManager();  // 00

		// override (BSTEventSink)
		BSEventNotifyControl ProcessEvent(const SPECIALMenuEvent::NameChangedEvent& a_event, BSTEventSource<SPECIALMenuEvent::NameChangedEvent>* a_source) override;  // 01

		[[nodiscard]] static BGSSaveLoadManager* GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadManager**> singleton{ REL::ID(2697802) };
			return *singleton;
		}

		void QueueSaveLoadTask(QUEUED_TASK a_task)
		{
			using func_t = decltype(&BGSSaveLoadManager::QueueSaveLoadTask);
			static REL::Relocation<func_t> func{ REL::ID(2228080) };
			return func(this, a_task);
		}

		// members
		BSTArray<BGSSaveLoadFileEntry*>          saveGameList;                  // 008
		bool                                     isSaveListBuilt;               // 020
		std::uint32_t                            saveGameCount;                 // 024
		std::uint32_t                            currentSaveGameNumber;         // 028
		std::uint64_t                            saveGameListBuildID;           // 030
		std::int32_t                             currentAutoSaveNumber;         // 038
		bool                                     simulatedMode;                 // 03C
		bool                                     autosaveDisabledForDiskspace;  // 03D
		std::uint32_t                            queuedTasks;                   // 040
		std::uint32_t                            saveOperationDelayCounter;     // 044
		BGSSaveLoadFileEntry*                    queuedEntryToLoad;             // 048
		std::uint64_t                            lastSaveTime;                  // 050
		bool                                     savingAllowed;                 // 058
		char*                                    mostRecentSaveGame;            // 060
		std::int32_t                             mostRecentSaveGameDeviceID;    // 068
		BSTHashMap<std::uint64_t, BSFixedString> playerIDNameMap;               // 070
		BSTHashMap<BSFixedString, BSFixedString> editorIdLocationMap;           // 0A0
		std::uint64_t                            currentPlayerID;               // 0D0
		std::uint64_t                            displayPlayerID;               // 0D8
		BSFixedString                            savefileNameToDelete;          // 0E0
		BSTHashMap<std::uint32_t, BSFixedString> autosaveFileNames;             // 0E8
		BSFixedString                            quicksaveFileName;             // 118
		BSFixedString                            exitsaveFileName;              // 120
		bool                                     hasSaveData;                   // 128
		BGSSaveLoadFile*                         saveLoadFile;                  // 130
		bool                                     returnedFromSysUtil;           // 138
		bool                                     sysUtilLoadDataComplete;       // 139
		SaveCompleteCallback_t                   sysUtilSaveCompleteCallback;   // 140
		LoadCompleteCallback_t                   sysUtilLoadCompleteCallback;   // 148
		BSSaveDataSystemUtilityImage             saveDataCreateImage;           // 150
		BSSaveDataSystemUtilityImage             saveDataBackgroundImage;       // 168
		BSSaveDataSystemUtilityImage             saveDataIconEncodedImage;      // 180
		NiPointer<NiTexture>                     screenshot[1];                 // 198
		BGSSaveLoadThread                        saveLoadTasksThread;           // 200
	};
	static_assert(sizeof(BGSSaveLoadManager) == 0x980);
}
