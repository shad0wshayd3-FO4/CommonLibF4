#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class __declspec(novtable) BGSColorForm :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSColorForm };
		static constexpr auto VTABLE{ VTABLE::BGSColorForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCLFM };

		// members
		union
		{
			std::uint32_t color;
			float         remappingIndex;
		};  // 30
		TESCondition  conditions;  // 38
		std::uint32_t flags;       // 40
	};
	static_assert(sizeof(BGSColorForm) == 0x48);
}
