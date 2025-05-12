#pragma once

namespace RE
{
	struct BSTObjectArenaScrapAllocBase
	{
	public:
		// members
		ScrapHeap* scrapHeap{ MemoryManager::GetSingleton().GetThreadScrapHeap() };  // 0
	};
	static_assert(sizeof(BSTObjectArenaScrapAllocBase) == 0x8);
}
