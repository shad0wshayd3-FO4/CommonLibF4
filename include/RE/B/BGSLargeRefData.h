#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class QueuedPromoteLargeReferencesTask;

	class BGSLargeRefData
	{
	public:
		struct REF_CELL_DATA
		{
		public:
			// members
			std::uint32_t refID;          // 0
			std::uint32_t parentCellKey;  // 4
		};
		static_assert(sizeof(REF_CELL_DATA) == 0x8);

		// members
		BSTHashMap<std::uint32_t, BSTArray<REF_CELL_DATA>*>                    cellOverlappingRefMap;  // 00
		BSTHashMap<std::uint32_t, NiPointer<QueuedPromoteLargeReferencesTask>> cellPromoteTaskMap;     // 30
	};
	static_assert(sizeof(BGSLargeRefData) == 0x60);
}
