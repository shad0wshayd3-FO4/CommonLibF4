#pragma once

namespace RE
{
	class __declspec(novtable) TESWordOfPower :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWordOfPower };
		static constexpr auto VTABLE{ VTABLE::TESWordOfPower };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWOOP };

		// members
		BGSLocalizedString translation;  // 30
	};
	static_assert(sizeof(TESWordOfPower) == 0x38);
}
