#pragma once

namespace RE
{
	struct BSTObjectArenaScrapAlloc :
		private BSTObjectArenaScrapAllocBase  // 0
	{
	public:
		[[nodiscard]] void* allocate_bytes(std::size_t a_bytes) { return scrapHeap->Allocate(a_bytes, 0x8); }
		void                deallocate_bytes(void* a_ptr) { scrapHeap->Deallocate(a_ptr); }
	};
	static_assert(sizeof(BSTObjectArenaScrapAlloc) == 0x8);
}
