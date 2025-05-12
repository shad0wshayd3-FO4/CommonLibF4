#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSAttackDataForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackDataForm };
		static constexpr auto VTABLE{ VTABLE::BGSAttackDataForm };

		// members
		NiPointer<BGSAttackDataMap> attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
