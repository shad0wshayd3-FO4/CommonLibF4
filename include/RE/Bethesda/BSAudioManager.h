#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiPoint.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	namespace BSExternalAudioIO
	{
		class ExternalIOInterface;
	}

	class BSAudioManagerThread;
	class BSGameSound;
	class BSISoundDescriptor;
	struct BSISoundDescriptor::ExtraResolutionData;
	class BSISoundOutputModel;
	class BSMultisound;
	class BSSoundInfo;
	class SoundMessageList;
	class SoundMessageStack;

	class BSAudioCallbacks
	{
	public:
		using IDCallback_t = bool (*)(std::uint32_t, const BSISoundDescriptor**);
		using NameCallback_t = bool (*)(const char*, const BSISoundDescriptor**);
		using PostProcessCallback = void (*)();

		// members
		IDCallback_t        idCallback;           // 00
		NameCallback_t      nameCallback;         // 08
		PostProcessCallback postProcessCallback;  // 10
	};
	static_assert(sizeof(BSAudioCallbacks) == 0x18);

	class BSAudioInit
	{
	public:
		// members
		BSAudioCallbacks                              audioCallbacks;         // 00
		BSFixedString                                 systemName;             // 18
		BSFixedString                                 missingAssetSoundFile;  // 20
		const BSExternalAudioIO::ExternalIOInterface* extIOInterface;         // 28
		std::uint32_t                                 initialCacheSize;       // 30
		std::uint32_t                                 maxAudioCacheSize;      // 34
		std::uint32_t                                 maxSizeForCachedSound;  // 38
		std::uint32_t                                 audioHWThread;          // 3C
		std::uint32_t                                 streamingThreshold;     // 40
		float                                         defaultMasterVolume;    // 44
		bool                                          runDisabled;            // 48
		bool                                          enableAudioCache;       // 49
		bool                                          enableAsyncLoads;       // 4A
	};
	static_assert(sizeof(BSAudioInit) == 0x50);

	class BSAudioManager
	{
	public:
		struct SyncedPlaybackManager
		{
		public:
			// members
			BSTArray<BSTSmallArray<std::uint32_t, 2>*> syncFamilies;  // 00
		};
		static_assert(sizeof(SyncedPlaybackManager) == 0x18);

		[[nodiscard]] static BSAudioManager* GetSingleton()
		{
			static REL::Relocation<BSAudioManager**> singleton{ REL::ID(1321158) };
			return *singleton;
		}

		void GetSoundHandleByName(BSSoundHandle& a_handle, const char* a_soundName, float a_distance, std::uint32_t a_usageFlags, BSISoundDescriptor::ExtraResolutionData* a_data)
		{
			using func_t = decltype(&BSAudioManager::GetSoundHandleByName);
			static REL::Relocation<func_t> func{ REL::ID(196484) };
			return func(this, a_handle, a_soundName, a_distance, a_usageFlags, a_data);
		}

		// members
		std::int32_t                                              messageListIndex;            // 000
		std::int32_t                                              messageProcessingListIndex;  // 004
		SoundMessageList*                                         messages[2];                 // 008
		SoundMessageStack*                                        freeMessages;                // 018
		SoundMessageStack*                                        garbageMessages;             // 020
		BSTHashMap<std::uint32_t, BSGameSound*>                   soundMap;                    // 028
		BSTHashMap<std::uint32_t, BSSoundInfo*>                   soundStateMap;               // 058
		BSTHashMap<std::uint32_t, NiPointer<NiAVObject>>          movingRefrMap;               // 088
		BSTHashMap<const NiAVObject*, const BSISoundOutputModel*> outputOverrideMap;           // 0B8
		BSTHashMap<const BSISoundOutputModel*, float>             opmFrequencyOverrideMap;     // 0E8
		BSTHashMap<std::uint32_t, BSMultisound*>                  multisoundMap;               // 118
		BSTHashMap<const NiAVObject*, NiPoint3>                   locationOverrideMap;         // 148
		SyncedPlaybackManager                                     syncManager;                 // 178
		void*                                                     cachedSoundList;             // 190 - BSTList<BSGameSound*>
		std::uint32_t                                             currentCacheSize;            // 198
		std::uint32_t                                             audioThreadID;               // 19C
		BSAudioManagerThread*                                     updateThread;                // 1A0
		std::uint32_t                                             audioThreadSleepTime;        // 1A8
		std::uint32_t                                             audioHWThread;               // 1AC
		BSAudioInit                                               initSettings;                // 1B0
		std::uint32_t                                             audioCacheSize;              // 200
		std::uint32_t                                             maxAudioCacheSize;           // 204
		std::uint32_t                                             maxSizeForCachedSound;       // 208
		std::uint32_t                                             stateFlags;                  // 20C
		float                                                     masterVolume;                // 210
		std::uint8_t                                              asyncPriorityThreshold;      // 214
		float                                                     invSpeedInUnitsPerMS;        // 218
		BSAudioCallbacks                                          audioCallbacks;              // 220
	};
	static_assert(sizeof(BSAudioManager) == 0x238);
}
