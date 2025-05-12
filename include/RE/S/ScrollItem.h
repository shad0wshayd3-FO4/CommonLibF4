#pragma once

namespace RE
{
	class __declspec(novtable) ScrollItem :
		public SpellItem,                  // 000
		public BGSModelMaterialSwap,       // 130
		public BGSDestructibleObjectForm,  // 170
		public BGSPickupPutdownSounds,     // 180
		public TESWeightForm,              // 198
		public TESValueForm                // 1A8
	{
	public:
		static constexpr auto RTTI{ RTTI::ScrollItem };
		static constexpr auto VTABLE{ VTABLE::ScrollItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSCRL };
	};
	static_assert(sizeof(ScrollItem) == 0x1B8);
}
