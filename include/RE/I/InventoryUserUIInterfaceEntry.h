#pragma once

namespace RE
{
	struct InventoryUserUIInterfaceEntry
	{
	public:
		// members
		InventoryInterface::Handle     invHandle;   // 00
		BSTSmallArray<std::uint8_t, 4> stackIndex;  // 08
	};
	static_assert(sizeof(InventoryUserUIInterfaceEntry) == 0x20);
}
