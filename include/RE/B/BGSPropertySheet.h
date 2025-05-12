#pragma once

namespace RE
{
	class __declspec(novtable) BGSPropertySheet :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPropertySheet };
		static constexpr auto VTABLE{ VTABLE::BGSPropertySheet };

		// members
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* properties;  // 08
	};
	static_assert(sizeof(BGSPropertySheet) == 0x10);
}
