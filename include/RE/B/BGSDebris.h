#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSDebrisData;

	class __declspec(novtable) BGSDebris :
		public TESForm,        // 00
		public BGSPreloadable  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDebris };
		static constexpr auto VTABLE{ VTABLE::BGSDebris };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDEBR };

		// members
		BSSimpleList<BGSDebrisData*> dataList;  // 28
	};
	static_assert(sizeof(BGSDebris) == 0x38);
}
