#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSFootstep :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSFootstep };
		static constexpr auto VTABLE{ VTABLE::BGSFootstep };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kFSTP };

		// members
		BSFixedString     tagString;  // 20
		BGSImpactDataSet* impactSet;  // 28
	};
	static_assert(sizeof(BGSFootstep) == 0x30);
}
