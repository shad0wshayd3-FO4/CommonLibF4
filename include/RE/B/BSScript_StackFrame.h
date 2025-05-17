#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSScript_Variable.h"

namespace RE
{
	namespace BSScript
	{
		class IFunction;
		class ObjectTypeInfo;
		class Stack;

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
