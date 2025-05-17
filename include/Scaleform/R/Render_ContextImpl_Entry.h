#pragma once

#include "Scaleform/L/List.h"

namespace Scaleform::Render::ContextImpl
{
	class EntryChange;
	class EntryData;
	class TreeCacheNode;

	class Entry
	{
	public:
		class PropagateNode :
			public ListNode<PropagateNode>  // 00
		{
		public:
		};
		static_assert(sizeof(PropagateNode) == 0x10);

		// members
		union
		{
			Entry*       prev;
			EntryChange* change;
		};  // 00
		union
		{
			Entry*      next;
			std::size_t refCount;
		};  // 08
		EntryData*     native;    // 10
		TreeCacheNode* renderer;  // 18
		Entry*         parent;    // 20
		PropagateNode  node;      // 28
	};
	static_assert(sizeof(Entry) == 0x38);
}
