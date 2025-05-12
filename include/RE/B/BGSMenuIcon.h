#pragma once

namespace RE
{
	class __declspec(novtable) BGSMenuIcon :
		public TESForm,  // 00
		public TESIcon   // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMenuIcon };
		static constexpr auto VTABLE{ VTABLE::BGSMenuIcon };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMICN };
	};
	static_assert(sizeof(BGSMenuIcon) == 0x30);
}
