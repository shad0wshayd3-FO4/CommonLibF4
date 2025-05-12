#pragma once

namespace RE
{
	class __declspec(novtable) TESKey :
		public TESObjectMISC  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESKey };
		static constexpr auto VTABLE{ VTABLE::TESKey };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kKEYM };
	};
	static_assert(sizeof(TESKey) == 0x168);
}
