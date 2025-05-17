#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIMusicType.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSMusicType :
		public TESForm,      // 00
		public BSIMusicType  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMusicType };
		static constexpr auto VTABLE{ VTABLE::BGSMusicType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMUSC };

		// members
		BSFixedString formEditorID;  // 70
	};
	static_assert(sizeof(BGSMusicType) == 0x78);
}
