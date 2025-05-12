#pragma once

namespace RE
{
	class __declspec(novtable) ExtraCharge :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraCharge };
		static constexpr auto VTABLE{ VTABLE::ExtraCharge };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kCharge };

		// members
		float charge;  // 18
	};
	static_assert(sizeof(ExtraCharge) == 0x20);
}
