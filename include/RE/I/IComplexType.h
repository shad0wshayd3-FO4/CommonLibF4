#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	namespace BSScript
	{
		class TypeInfo;

		class __declspec(novtable) IComplexType :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IComplexType };
			static constexpr auto VTABLE{ VTABLE::BSScript__IComplexType };

			// TODO: Verify that setting this to default doesn't fuck everything up
			virtual ~IComplexType() = default;  // 00

			// add
			virtual TypeInfo::RawType GetRawType() const = 0;  // 01

			[[nodiscard]] bool IsObject() const { return GetRawType() == TypeInfo::RawType::kObject; }
		};
		static_assert(sizeof(IComplexType) == 0x10);
	}
}
