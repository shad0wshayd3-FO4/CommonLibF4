#pragma once

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
