#pragma once

namespace RE
{
	struct BSAnimationGraphVariableCache
	{
	public:
		// members
		BSTArray<AnimVariableCacheInfo>      variableCache;        // 00
		BSTArray<hkbVariableValue*>          variableQuickLookup;  // 18
		BSSpinLock* lock;                 // 30
		BSTSmartPointer<BShkbAnimationGraph> graphToCacheFor;      // 38
	};
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x40);
}
