#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESGlobal :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESGlobal };
		static constexpr auto VTABLE{ VTABLE::TESGlobal };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kGLOB };

		[[nodiscard]] float GetValue() const noexcept { return value; }

		// members
		BSString formEditorID;  // 20
		float    value;         // 30
	};
	static_assert(sizeof(TESGlobal) == 0x38);
}
