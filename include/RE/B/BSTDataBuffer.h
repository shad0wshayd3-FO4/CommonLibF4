#pragma once

namespace RE
{
	class BSDataBufferHeapAllocator;

	template <std::uint32_t N, class Allocator = BSDataBufferHeapAllocator>
	class BSTDataBuffer
	{
	public:
		class Block
		{
		public:
			// members
			std::uint32_t size: 24;  // 0:00
			std::uint32_t id: 8;     // 0:24
		};
		static_assert(sizeof(Block) == 0x4);

		[[nodiscard]] std::pair<const Block*, std::uint32_t> GetBlock(std::uint8_t a_id) const noexcept
		{
			if (!buffer) {
				return { nullptr, 0 };
			}

			std::uint32_t offset = 0;
			const auto    blocks = reinterpret_cast<const Block*>(buffer + size);
			for (std::uint32_t i = 0; i < N && blocks[i].id != 0xFFu; ++i) {
				if (blocks[i].id == a_id) {
					return { blocks + i, offset };
				} else {
					offset += blocks[i].size;
				}
			}

			return { nullptr, 0 };
		}

		template <class T>
		[[nodiscard]] std::span<T> GetBuffer(std::uint8_t a_id) const noexcept
		{
			const auto [block, offset] = GetBlock(a_id);
			if (block) {
				return { reinterpret_cast<T*>(buffer + offset), block->size / sizeof(T) };
			} else {
				return {};
			}
		}

		// members
		std::byte*    buffer;  // 00
		std::uint32_t size;    // 08
	};

	extern template class BSTDataBuffer<1>;
	extern template class BSTDataBuffer<2>;
}
