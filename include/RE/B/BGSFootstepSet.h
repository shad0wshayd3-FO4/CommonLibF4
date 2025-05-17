#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSFootstepSet :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSFootstepSet };
		static constexpr auto VTABLE{ VTABLE::BGSFootstepSet };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kFSTS };

		// members
		BSTArray<BGSFootstep*> entries[5];  // 20
	};
	static_assert(sizeof(BGSFootstepSet) == 0x98);
}
