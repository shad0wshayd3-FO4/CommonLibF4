#pragma once

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
		BSStringT<char> formEditorID;  // 28
	};
	static_assert(sizeof(BGSVoiceType) == 0x38);
}
