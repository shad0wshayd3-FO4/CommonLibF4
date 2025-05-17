#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class __declspec(novtable) TESEyes :
		public TESForm,      // 00
		public TESFullName,  // 20
		public TESTexture    // 30
	{
	public:
		static constexpr auto RTTI{ RTTI::TESEyes };
		static constexpr auto VTABLE{ VTABLE::TESEyes };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kEYES };

		// members
		std::int8_t flags;  // 40
	};
	static_assert(sizeof(TESEyes) == 0x48);
}
