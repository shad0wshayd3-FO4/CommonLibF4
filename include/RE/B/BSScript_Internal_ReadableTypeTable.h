#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ReadableTypeTable
			{
			public:
				class SaveTypeInfo :
					public BSIntrusiveRefCounted  // 00
				{
				public:
					// members
					BSFixedString               parentType;        // 08
					BSScrapArray<std::uint32_t> variableIndicies;  // 10
				};
				static_assert(sizeof(SaveTypeInfo) == 0x30);

				// members
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<SaveTypeInfo>>* saveTypeInfo;  // 00
			};
			static_assert(sizeof(ReadableTypeTable) == 0x08);
		}
	}
}
