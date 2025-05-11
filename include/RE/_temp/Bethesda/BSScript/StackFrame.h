#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IFunction.h"
#include "RE/Bethesda/BSScript/ObjectTypeInfo.h"
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
		class IFunction;
		class ObjectTypeInfo;
		class Stack;
		class Variable;

		class StackFrame
		{
		public:
			[[nodiscard]] std::uint32_t GetPageForFrame() const;
			[[nodiscard]] Variable&     GetStackFrameVariable(std::uint32_t a_index, std::uint32_t a_pageHint) const;

			// members
			Stack*                          parent;             // 00
			StackFrame*                     previousFrame;      // 08
			BSTSmartPointer<IFunction>      owningFunction;     // 10
			BSTSmartPointer<ObjectTypeInfo> owningObjectType;   // 18
			std::uint32_t                   ip;                 // 20
			Variable                        self;               // 28
			std::uint32_t                   size;               // 38
			bool                            instructionsValid;  // 3C
		};
		static_assert(sizeof(StackFrame) == 0x40);
	}
}
