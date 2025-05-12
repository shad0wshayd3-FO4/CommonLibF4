#pragma once

namespace RE
{
	class __declspec(novtable) ExtraReferenceHandles :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraReferenceHandles };
		static constexpr auto VTABLE{ VTABLE::ExtraReferenceHandles };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kReferenceHandle };

		// members
		ObjectRefHandle originalRef;   // 18
		ObjectRefHandle containerRef;  // 1C
	};
	static_assert(sizeof(ExtraReferenceHandles) == 0x20);
}
