#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSAssociationType :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAssociationType };
		static constexpr auto VTABLE{ VTABLE::BGSAssociationType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kASTP };

		// members
		BSFixedStringCS associationLabel[2][2];  // 20
		std::uint32_t   flags;                   // 40
	};
	static_assert(sizeof(BGSAssociationType) == 0x48);
}
