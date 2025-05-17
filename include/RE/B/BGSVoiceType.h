#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESForm.h"
#include "RE/V/VOICE_TYPE_DATA.h"

namespace RE
{
	class __declspec(novtable) BGSVoiceType :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSVoiceType };
		static constexpr auto VTABLE{ VTABLE::BGSVoiceType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kVTYP };

		// members
		VOICE_TYPE_DATA data;          // 20
		BSString        formEditorID;  // 28
	};
	static_assert(sizeof(BGSVoiceType) == 0x38);
}
