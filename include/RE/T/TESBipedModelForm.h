#pragma once

namespace RE
{
	class __declspec(novtable) TESBipedModelForm :
		public BaseFormComponent  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESBipedModelForm };
		static constexpr auto VTABLE{ VTABLE::TESBipedModelForm };

		// members
		BGSModelMaterialSwap worldModel[2];       // 008
		TESIcon              inventoryIcon[2];    // 088
		BGSMessageIcon       messageIcon[2];      // 0A8
		TESModelRDT          constraintTemplate;  // 0D8
	};
	static_assert(sizeof(TESBipedModelForm) == 0x108);

}
