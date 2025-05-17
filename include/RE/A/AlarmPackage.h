#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/T/TESPackage.h"

namespace RE
{
	class Crime;

	class __declspec(novtable) AlarmPackage :
		public TESPackage  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::AlarmPackage };
		static constexpr auto VTABLE{ VTABLE::AlarmPackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// members
		BSSimpleList<Crime*> crimes;      // C8
		bool                 forceGreet;  // D8
	};
	static_assert(sizeof(AlarmPackage) == 0xE0);
}
