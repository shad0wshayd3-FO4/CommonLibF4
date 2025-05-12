#pragma once

namespace RE
{
	class __declspec(novtable) TESModelRDT :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModelRDT };
		static constexpr auto VTABLE{ VTABLE::TESModelRDT };
	};
	static_assert(sizeof(TESModelRDT) == 0x30);
}
