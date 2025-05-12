#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class __declspec(novtable) TESLevSpell :
		public TESBoundObject,  // 00
		public TESLeveledList   // 68
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLevSpell };
		static constexpr auto VTABLE{ VTABLE::TESLevSpell };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLVSP };
	};
	static_assert(sizeof(TESLevSpell) == 0x98);
}
