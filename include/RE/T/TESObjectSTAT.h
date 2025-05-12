#pragma once

namespace RE
{
	class __declspec(novtable) TESObjectSTAT :
		public TESBoundObject,        // 00
		public BGSModelMaterialSwap,  // 68
		public BGSPropertySheet,      // A8
		public BGSForcedLocRefType,   // B8
		public BGSNavmeshableObject   // C8
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectSTAT };
		static constexpr auto VTABLE{ VTABLE::TESObjectSTAT };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSTAT };

		// members
		TESObjectSTATData data;  // D0
	};
	static_assert(sizeof(TESObjectSTAT) == 0xE8);
}
