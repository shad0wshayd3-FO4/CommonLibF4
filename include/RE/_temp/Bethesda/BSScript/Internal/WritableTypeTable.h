#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;
		class StructTypeInfo;

		namespace Internal
		{
			class WritableTypeTable
			{
			public:
				// members
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>* objectTypeMap;  // 00
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>>* structTypeMap;  // 08
			};
			static_assert(sizeof(WritableTypeTable) == 0x10);
		}
	}
}
