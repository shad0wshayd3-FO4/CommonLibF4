#pragma once

#include "Scaleform/L/List.h"

namespace Scaleform::Render::ContextImpl
{
	class Snapshot;
	class SnapshotPage;

	class EntryPageBase :
		public ListNode<EntryPageBase>  // 00
	{
	public:
		// members
		std::uint32_t useCount;             // 10
		Snapshot*     snapshot;             // 18
		SnapshotPage* snapshotPage;         // 20
		SnapshotPage* displaySnapshotPage;  // 28
		SnapshotPage* tempPage;             // 30
	};
	static_assert(sizeof(EntryPageBase) == 0x38);
}
