#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace BSScript
	{
		class Object;

		namespace Internal
		{
			class EventRelay :
				public BSIntrusiveRefCounted  // 00
			{
			public:
				struct TargetList :
					public BSIntrusiveRefCounted  // 00
				{
				public:
					// members
					BSTSet<BSTSmartPointer<Object>> targets;  // 00
				};
				static_assert(sizeof(TargetList) == 0x38);

				// members
				BSTHashMap<BSFixedString, BSTSmartPointer<TargetList>> events;  // 00
			};
			static_assert(sizeof(EventRelay) == 0x38);
		}
	}
}
