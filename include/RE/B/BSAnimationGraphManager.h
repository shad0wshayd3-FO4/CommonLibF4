#pragma once

#include "RE/B/BSAnimationGraphVariableCache.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	class BSAnimationGraphChannel;
	class BShkbAnimationGraph;
	class BSAnimationGraphEvent;

	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,  //00
		public BSIntrusiveRefCounted                 //08
	{
	public:
		class DependentManagerSmartPtr
		{
		public:
			// members
			std::uint64_t ptrAndFlagsStorage;  // 00
		};
		static_assert(sizeof(DependentManagerSmartPtr) == 0x08);

		// members
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>     boundChannel;          // 10
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>     bumpedChannel;         // 28
		BSTSmallArray<BSTSmartPointer<BShkbAnimationGraph>, 1> graph;                 // 40
		BSTArray<DependentManagerSmartPtr>                     subManagers;           // 58
		BSTArray<BSTTuple<BSFixedString, BSFixedString>>       eventQueuea;           // 70
		BSAnimationGraphVariableCache                          variableCache;         // 88
		BSSpinLock                                             updateLock;            // C8
		BSSpinLock                                             dependentManagerLock;  // D0
		std::uint32_t                                          activeGraph;           // D8
		std::uint32_t                                          generateDepth;         // DC
	};
	static_assert(sizeof(BSAnimationGraphManager) == 0xE0);
}
