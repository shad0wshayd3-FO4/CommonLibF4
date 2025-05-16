#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSSoundCategorySnapshot :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundCategorySnapshot };
		static constexpr auto VTABLE{ VTABLE::BGSSoundCategorySnapshot };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSCSN };

		// members
		BSTHashMap<BGSSoundCategory*, float> categoryMult;  // 20
		std::int8_t                          priority;      // 50
	};
	static_assert(sizeof(BGSSoundCategorySnapshot) == 0x58);
}
