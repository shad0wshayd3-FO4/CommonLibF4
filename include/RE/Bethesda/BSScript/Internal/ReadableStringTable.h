#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			enum class StringIndexSize
			{
				kSmall,
				kLarge
			};

			class ReadableStringTable
			{
			public:
				class StringEntry
				{
				public:
					// members
					const char*   originalData;     // 00
					BSFixedString convertedString;  // 08
				};
				static_assert(sizeof(StringEntry) == 0x10);

				class StringTableScrapPage
				{
				public:
					// members
					char              buffer[0x1000];  // 0000
					char*             curr;            // 1000
					const char* const end;             // 1008
				};
				static_assert(sizeof(StringTableScrapPage) == 0x1010);

				// members
				msvc::unique_ptr<BSTObjectArena<StringTableScrapPage, BSTObjectArenaScrapAlloc, 1>> scrapPages;  // 00
				msvc::unique_ptr<BSScrapArray<StringEntry>>                                         entries;     // 08
				REX::EnumSet<StringIndexSize, std::int32_t>                                         indexSize;   // 10
			};
			static_assert(sizeof(ReadableStringTable) == 0x18);
		}
	}
}
