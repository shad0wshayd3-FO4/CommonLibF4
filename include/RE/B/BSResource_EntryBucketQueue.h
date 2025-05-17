#pragma once

#include "RE/B/BSResource_EntryQueue.h"

namespace RE::BSResource
{
	template <class T, std::uint32_t N>
	class EntryBucketQueue
	{
	public:
		// members
		EntryQueue<T>          buckets[N];  // 00
		volatile std::uint32_t step;        // ??
	};
	static_assert(sizeof(EntryBucketQueue<void, 8>) == 0xC8);
}
