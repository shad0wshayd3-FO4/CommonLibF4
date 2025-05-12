#pragma once

namespace RE
{
	class __declspec(novtable) TESLevItem :
		public TESBoundObject,  // 00
		public TESLeveledList   // 68
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLevItem };
		static constexpr auto VTABLE{ VTABLE::TESLevItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLVLI };
	};
	static_assert(sizeof(TESLevItem) == 0x98);
}
