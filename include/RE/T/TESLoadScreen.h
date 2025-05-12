#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESLoadScreen :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLoadScreen };
		static constexpr auto VTABLE{ VTABLE::TESLoadScreen };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLSCR };

		struct LoadNIFData;

		// members
		TESCondition       conditions;   // 20
		LoadNIFData*       loadNIFData;  // 28
		BGSLocalizedString loadingText;  // 30
	};
	static_assert(sizeof(TESLoadScreen) == 0x38);
}
