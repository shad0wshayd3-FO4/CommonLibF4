#pragma once

#include "Scaleform/L/List.h"

namespace Scaleform
{
	class MemoryHeap;

	namespace Render::ContextImpl
	{
		class Context;
		class Entry;
		class EntryListAccessor;
		class EntryPage;
		class EntryPageBase;
		class Snapshot;

		class EntryTable
		{
		public:
			// members
			Context*                        context;         // 00
			MemoryHeap*                     heap;            // 08
			List<EntryPage, EntryPageBase>  entryPages;      // 10
			List2<Entry, EntryListAccessor> freeNodes;       // 20
			Snapshot*                       activeSnapshot;  // 58
		};
		static_assert(sizeof(EntryTable) == 0x60);
	}
}
