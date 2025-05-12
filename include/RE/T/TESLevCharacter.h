#pragma once

namespace RE
{
	class __declspec(novtable) TESLevCharacter :
		public TESBoundAnimObject,   // 00
		public TESLeveledList,       // 68
		public BGSModelMaterialSwap  // 98
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLevCharacter };
		static constexpr auto VTABLE{ VTABLE::TESLevCharacter };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLVLN };
	};
	static_assert(sizeof(TESLevCharacter) == 0xD8);
}
