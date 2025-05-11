#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class IFunction;

		struct PropertyTypeInfo
		{
		public:
			enum class Permissions
			{
			};

			// members
			BSFixedString                            parentObjName;  // 00
			BSFixedString                            propertyName;   // 08
			TypeInfo                                 type;           // 10
			REX::EnumSet<Permissions, std::uint32_t> permissions;    // 18
			std::uint32_t                            pad1C;          // 1C
			BSTSmartPointer<IFunction>               getFunction;    // 20
			BSTSmartPointer<IFunction>               setFunction;    // 28
			std::uint32_t                            autoVarIndex;   // 30
			std::uint32_t                            userFlags;      // 34
			BSFixedString                            docString;      // 38
		};
		static_assert(sizeof(PropertyTypeInfo) == 0x40);
	}
}
