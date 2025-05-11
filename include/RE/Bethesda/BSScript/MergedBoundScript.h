#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class BoundScript;  // stub

		class MergedBoundScript
		{
		public:
			// members
			BSTSmartPointer<BoundScript> childScript;   // 00
			BSTSmartPointer<BoundScript> parentScript;  // 08
		};
		static_assert(sizeof(MergedBoundScript) == 0x10);
	}
}
