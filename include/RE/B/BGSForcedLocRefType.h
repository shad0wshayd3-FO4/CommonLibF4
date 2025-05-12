#pragma once

namespace RE
{
	class __declspec(novtable) BGSForcedLocRefType :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSForcedLocRefType };
		static constexpr auto VTABLE{ VTABLE::BGSForcedLocRefType };

		// members
		BGSLocationRefType* forcedType;  // 08
	};
	static_assert(sizeof(BGSForcedLocRefType) == 0x10);
}
