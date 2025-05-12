#pragma once

namespace RE
{
	class __declspec(novtable) TESModelTri :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModelTri };
		static constexpr auto VTABLE{ VTABLE::TESModelTri };
	};
	static_assert(sizeof(TESModelTri) == 0x30);
}
