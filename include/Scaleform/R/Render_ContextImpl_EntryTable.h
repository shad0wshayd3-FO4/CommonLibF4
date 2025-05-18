#pragma once

#include "Scaleform/L/List.h"
#include "Scaleform/R/Render_ContextImpl_Entry.h"
#include "Scaleform/R/Render_ContextImpl_EntryListAccessor.h"
#include "Scaleform/R/Render_ContextImpl_EntryPage.h"
#include "Scaleform/R/Render_ContextImpl_EntryPageBase.h"

namespace Scaleform
{
	class MemoryHeap;

	namespace Render::ContextImpl
	{
		class Context;
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
