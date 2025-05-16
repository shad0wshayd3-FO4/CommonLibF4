#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/T/TESForm.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class __declspec(novtable) BGSSoundTagSet :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundTagSet };
		static constexpr auto VTABLE{ VTABLE::BGSSoundTagSet };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSTAG };

		// members
		BSTHashMap<BSFixedString, BGSSoundDescriptorForm*> soundTags;  // 20
	};
	static_assert(sizeof(BGSSoundTagSet) == 0x50);
}
