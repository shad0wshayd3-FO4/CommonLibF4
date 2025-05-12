#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESImageSpaceModifiableForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESImageSpaceModifiableForm };
		static constexpr auto VTABLE{ VTABLE::TESImageSpaceModifiableForm };

		// members
		TESImageSpaceModifier* formImageSpaceModifying;  // 08
	};
	static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10);
}
