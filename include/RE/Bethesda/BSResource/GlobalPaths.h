#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSResource/Location.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSingleton.h"

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
			static REL::Relocation<GlobalPaths**> singleton{ REL::ID(210868) };
			return *singleton;
		}

		// members
		BSTArray<BSFixedString> names;         // 18
		Location*               rootLocation;  // 30
	};
	static_assert(sizeof(GlobalPaths) == 0x38);
}
