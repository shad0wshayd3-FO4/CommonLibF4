#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

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
