#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BSFixedString.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESObjectANIO :
		public TESForm,              // 00
		public BGSModelMaterialSwap  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectANIO };
		static constexpr auto VTABLE{ VTABLE::TESObjectANIO };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kANIO };

		// members
		BSFixedString formEditorID;     // 60
		BSFixedString unloadEventName;  // 68
	};
	static_assert(sizeof(TESObjectANIO) == 0x70);
}
