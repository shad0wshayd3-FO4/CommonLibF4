#pragma once

namespace RE
{
	class __declspec(novtable) TESFlora :
		public TESObjectACTI,  // 000
		public TESProduceForm  // 148
	{
	public:
		static constexpr auto RTTI{ RTTI::TESFlora };
		static constexpr auto VTABLE{ VTABLE::TESFlora };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kFLOR };
	};
	static_assert(sizeof(TESFlora) == 0x168);
}
