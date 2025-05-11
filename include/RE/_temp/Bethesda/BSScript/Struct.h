#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/StructTypeInfo.h"
#include "RE/Bethesda/BSScript/Variable.h"
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
		class StructTypeInfo;
		class Variable;

		class Struct :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			~Struct();

			// members
			BSSpinLock                      structLock;           // 04
			BSTSmartPointer<StructTypeInfo> type;                 // 10
			bool                            constructed{ true };  // 18
			bool                            valid{ false };       // 19
			Variable                        variables[0];         // 20
		};
		static_assert(sizeof(Struct) == 0x20);
	}
}
