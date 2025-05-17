#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/M/Modifiers.h"

namespace RE
{
	class ActorValueStorage
	{
	public:
		// members
		BSTArray<BSTTuple<std::uint32_t, float>>     baseValues;  // 00
		BSTArray<BSTTuple<std::uint32_t, Modifiers>> modifiers;   // 18
		BSReadWriteLock                              avLock;      // 30
	};
	static_assert(sizeof(ActorValueStorage) == 0x38);
}
