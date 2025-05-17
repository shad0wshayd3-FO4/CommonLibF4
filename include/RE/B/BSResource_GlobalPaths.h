#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSResource_Location.h"

namespace RE::BSResource
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
			static REL::Relocation<GlobalPaths**> singleton{ RE::ID::BSResource_GlobalPaths::Singleton };
			return *singleton;
		}

		// members
		BSTArray<BSFixedString> names;         // 18
		Location*               rootLocation;  // 30
	};
	static_assert(sizeof(GlobalPaths) == 0x38);
}
