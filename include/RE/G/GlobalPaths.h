#pragma once

#include "RE/L/Location.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	namespace BSResource
	{
		class __declspec(novtable) GlobalPaths :
			public Location,                     // 00
			public BSTSingletonSDM<GlobalPaths>  // 10
		{
		public:
			static constexpr auto RTTI{ RTTI::BSResource____GlobalPaths };
			static constexpr auto VTABLE{ VTABLE::BSResource____GlobalPaths };

			[[nodiscard]] static GlobalPaths* GetSingleton()
			{
				static REL::Relocation<GlobalPaths**> singleton{ REL::ID(210868) };
				return *singleton;
			}

			// members
			BSTArray<BSFixedString> names;         // 18
			Location*               rootLocation;  // 30
		};
		static_assert(sizeof(GlobalPaths) == 0x38);
	}
}
