#pragma once

namespace RE
{
	class __declspec(novtable) BGSInstanceNamingRulesForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSInstanceNamingRulesForm };
		static constexpr auto VTABLE{ VTABLE::BGSInstanceNamingRulesForm };

		// members
		BGSInstanceNamingRules* instanceNamingRules;  // 08
	};
	static_assert(sizeof(BGSInstanceNamingRulesForm) == 0x10);
}
