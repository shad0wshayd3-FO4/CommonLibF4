#pragma once

#include "RE/B/BSSpinLock.h"

namespace RE::BSResource
{
	template <class T>
	class EntryQueue
	{
	public:
		// members
		BSNonReentrantSpinLock lock;  // 00
		T*                     head;  // 08
		T**                    tail;  // 10
	};
	static_assert(sizeof(EntryQueue<void>) == 0x18);
}
