#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class Stack;

		namespace Internal
		{
			class IFuncCallQuery;

			class SuspendedStack
			{
			public:
				// members
				BSTSmartPointer<Stack>          stack;          // 00
				BSTSmartPointer<IFuncCallQuery> funcCallQuery;  // 08
			};
			static_assert(sizeof(SuspendedStack) == 0x10);
		}
	}
}
