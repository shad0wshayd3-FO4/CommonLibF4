#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class BoundScript;

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
