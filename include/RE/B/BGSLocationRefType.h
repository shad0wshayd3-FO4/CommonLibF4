#pragma once

#include "RE/B/BGSKeyword.h"

namespace RE
{
	class __declspec(novtable) BGSLocationRefType :
		public BGSKeyword  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSLocationRefType };
		static constexpr auto VTABLE{ VTABLE::BGSLocationRefType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLCRT };
	};
	static_assert(sizeof(BGSLocationRefType) == 0x28);
}
