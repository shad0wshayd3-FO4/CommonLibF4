#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTObjectArena.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			enum class StringIndexSize;

			class WritableStringTable
			{
			public:
				// members
				std::unique_ptr<BSTObjectArena<BSFixedString>>                 stringTable;         // 00
				std::unique_ptr<BSTScrapHashMap<BSFixedString, std::uint32_t>> stringReferenceMap;  // 08
				REX::EnumSet<StringIndexSize, std::int32_t>                    indexSize;           // 10
			};
			static_assert(sizeof(WritableStringTable) == 0x18);
		}
	}
}
