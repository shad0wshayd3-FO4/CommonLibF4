#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	struct INSTANCE_FILTER
	{
	public:
		// members
		std::uint32_t                                      levelOverride;     // 00
		std::uint8_t                                       tierStartLevel;    // 04
		std::uint8_t                                       altLevelsPerTier;  // 05
		bool                                               epic;              // 06
		BSScrapArray<BSTTuple<BGSKeyword*, std::uint32_t>> keywordChances;    // 08
	};
	static_assert(sizeof(INSTANCE_FILTER) == 0x28);
}
