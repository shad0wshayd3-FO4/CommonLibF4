#pragma once

namespace RE
{
	class __declspec(novtable) BGSComponent :
		public TESBoundObject,      // 00
		public TESFullName,         // 68
		public TESValueForm,        // 78
		public BGSCraftingUseSound  // 88
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSComponent };
		static constexpr auto VTABLE{ VTABLE::BGSComponent };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCMPO };

		// members
		TESObjectMISC* scrapItem;       // 98
		TESGlobal*     modScrapScalar;  // 90
	};
	static_assert(sizeof(BGSComponent) == 0xA8);
}
