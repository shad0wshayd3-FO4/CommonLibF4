#include "RE/B/BSTArray.h"

namespace RE
{
	template class BSTAlignedHeapArrayAllocator<0x10>::Allocator;
	static_assert(sizeof(BSTAlignedHeapArrayAllocator<0x10>::Allocator) == 0x10);
}
