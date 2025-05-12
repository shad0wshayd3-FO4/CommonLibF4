#pragma once

namespace RE
{
	namespace InventoryInterface
	{
		struct Handle;
	}

	template <>
	struct BSCRC32<InventoryInterface::Handle>
	{
		[[nodiscard]] std::uint32_t operator()(InventoryInterface::Handle a_data) const noexcept;
	};
}
