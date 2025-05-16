#pragma once

#include "RE/B/BSCRC32.h"

namespace RE
{
	class BGSInventoryItem;

	namespace InventoryInterface
	{
		struct CountChangedEvent
		{
		public:
			// members
			std::uint32_t inventoryOwnerID;  // 00
			std::uint32_t itemID;            // 04
			std::int32_t  newCount;          // 08
			std::int32_t  oldCount;          // 0C
		};
		static_assert(sizeof(CountChangedEvent) == 0x10);

		struct FavoriteChangedEvent
		{
		public:
			~FavoriteChangedEvent() noexcept {}  // intentional

			// members
			BGSInventoryItem* itemAffected;  // 0
		};
		static_assert(sizeof(FavoriteChangedEvent) == 0x8);

		struct Handle
		{
		public:
			~Handle() noexcept {}  // intentional

			// members
			std::uint32_t id;  // 0
		};
		static_assert(sizeof(Handle) == 0x4);
	}

	template <>
	struct BSCRC32<InventoryInterface::Handle>
	{
		[[nodiscard]] std::uint32_t operator()(InventoryInterface::Handle a_data) const noexcept;
	};
}
