#pragma once

namespace RE
{
	namespace BSScript
	{
		class PropertyGroupInfo :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			// members
			BSFixedString           groupName;      // 08
			BSFixedString           docString;      // 10
			std::uint32_t           userFlags;      // 18
			BSTArray<BSFixedString> propertyNames;  // 20
		};
		static_assert(sizeof(PropertyGroupInfo) == 0x38);
	}
}
