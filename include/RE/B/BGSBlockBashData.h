#pragma once

namespace RE
{
	class __declspec(novtable) BGSBlockBashData :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBlockBashData };
		static constexpr auto VTABLE{ VTABLE::BGSBlockBashData };

		// members
		BGSImpactDataSet* blockBashImpactDataSet;  // 08
		BGSMaterialType*  altBlockMaterialType;    // 10
	};
	static_assert(sizeof(BGSBlockBashData) == 0x18);
}
