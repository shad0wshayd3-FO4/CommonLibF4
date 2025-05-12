#pragma once

namespace RE
{
	class __declspec(novtable) ExtraUniqueID :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraUniqueID };
		static constexpr auto VTABLE{ VTABLE::ExtraUniqueID };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kUniqueID };

		// members
		std::uint16_t uniqueID;  // 18
		std::uint32_t baseID;    // 1C
	};
	static_assert(sizeof(ExtraUniqueID) == 0x20);
}
