#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSResource/Location.h"
#include "RE/Bethesda/BSTSingleton.h"

namespace RE::BSResource
{
	class __declspec(novtable) GlobalLocations :
		public Location,                         // 00
		public BSTSingletonSDM<GlobalLocations>  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::BSResource____GlobalLocations };
		static constexpr auto VTABLE{ VTABLE::BSResource____GlobalLocations };

		struct Entry
		{
		public:
			// members
			Entry*        next;      // 00
			Location*     location;  // 08
			std::uint32_t priority;  // 10
		};
		static_assert(sizeof(Entry) == 0x18);

		[[nodiscard]] static GlobalLocations* GetSingleton()
		{
			static REL::Relocation<GlobalLocations**> singleton{ REL::ID(1573818) };
			return *singleton;
		}

		// members
		BSSpinLock lock;          // 14
		Entry*     head;          // 20
		Entry*     pendingMount;  // 28
		Entry*     free;          // 30
	};
	static_assert(sizeof(GlobalLocations) == 0x38);
}
