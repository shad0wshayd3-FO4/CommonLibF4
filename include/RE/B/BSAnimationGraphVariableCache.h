#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class AnimVariableCacheInfo;
	class BShkbAnimationGraph;
	class BSSpinLock;
	class hkbVariableValue;

	class BSAnimationGraphVariableCache
	{
	public:
		// members
		BSTArray<AnimVariableCacheInfo>      variableCache;        // 00
		BSTArray<hkbVariableValue*>          variableQuickLookup;  // 18
		BSSpinLock*                          lock;                 // 30
		BSTSmartPointer<BShkbAnimationGraph> graphToCacheFor;      // 38
	};
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x40);
}
