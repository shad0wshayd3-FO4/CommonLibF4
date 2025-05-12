#pragma once

namespace RE
{
	class __declspec(novtable) BGSPackIn :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPackIn };
		static constexpr auto VTABLE{ VTABLE::BGSPackIn };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPKIN };
	};
	static_assert(sizeof(BGSPackIn) == 0x20);
}
