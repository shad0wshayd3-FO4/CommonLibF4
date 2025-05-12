#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESTexture.h"
#include "RE/B/BGSPropertySheet.h"

namespace RE
{
	class __declspec(novtable) TESClass :
		public TESForm,          // 00
		public TESFullName,      // 20
		public TESDescription,   // 30
		public TESTexture,       // 48
		public BGSPropertySheet  // 58
	{
	public:
		static constexpr auto RTTI{ RTTI::TESClass };
		static constexpr auto VTABLE{ VTABLE::TESClass };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCLAS };

		// members
		CLASS_DATA data;  // 68
	};
	static_assert(sizeof(TESClass) == 0x70);
}
