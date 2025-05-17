#pragma once

#include "RE/B/BSAudioCallbacks.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class BSAudioInit
	{
	public:
		// members
		BSAudioCallbacks audioCallbacks;         // 00
		BSFixedString    systemName;             // 18
		BSFixedString    missingAssetSoundFile;  // 20
		const void*      extIOInterface;         // 28 - BSExternalAudioIO::ExternalIOInterface
		std::uint32_t    initialCacheSize;       // 30
		std::uint32_t    maxAudioCacheSize;      // 34
		std::uint32_t    maxSizeForCachedSound;  // 38
		std::uint32_t    audioHWThread;          // 3C
		std::uint32_t    streamingThreshold;     // 40
		float            defaultMasterVolume;    // 44
		bool             runDisabled;            // 48
		bool             enableAudioCache;       // 49
		bool             enableAsyncLoads;       // 4A
	};
	static_assert(sizeof(BSAudioInit) == 0x50);
}
