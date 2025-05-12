#pragma once

namespace RE
{
	class __declspec(novtable) ExtraLocation :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLocation };
		static constexpr auto VTABLE{ VTABLE::ExtraLocation };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLocation };

		// members
		BGSLocation* location;  // 18
	};
	static_assert(sizeof(ExtraLocation) == 0x20);
}
