#pragma once

#include "Scaleform/L/List.h"

namespace Scaleform::Render::ContextImpl
{
	class EntryData;
	class EntryPage;

	class SnapshotPage :
		public ListNode<SnapshotPage>  // 000
	{
	public:
		// members
		EntryPage*    entryPage;          // 010
		SnapshotPage* olderSnapshotPage;  // 018
		SnapshotPage* newerSnapshotPage;  // 020
		EntryData*    data[72];           // 028
	};
	static_assert(sizeof(SnapshotPage) == 0x268);
}
