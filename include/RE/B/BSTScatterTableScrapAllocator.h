#pragma once

namespace RE
{
	template <std::size_t S, std::size_t A>
	class BSTScatterTableScrapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using propagate_on_container_move_assignment = std::false_type;

		BSTScatterTableScrapAllocator() = default;
		BSTScatterTableScrapAllocator(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator(BSTScatterTableScrapAllocator&&) = delete;
		~BSTScatterTableScrapAllocator() = default;
		BSTScatterTableScrapAllocator& operator=(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator& operator=(BSTScatterTableScrapAllocator&&) = delete;

		[[nodiscard]] static constexpr size_type min_size() noexcept { return 1u << 3; }

		[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
		{
			assert(_allocator != nullptr);
			assert(a_bytes % S == 0);
			return _allocator->Allocate(a_bytes, 0x10);
		}

		void deallocate_bytes(void* a_ptr)
		{
			assert(_allocator != nullptr);
			_allocator->Deallocate(a_ptr);
		}

		[[nodiscard]] void* get_entries() const noexcept { return _entries; }
		void                set_entries(void* a_entries) noexcept { _entries = static_cast<std::byte*>(a_entries); }

	private:
		// members
		ScrapHeap* _allocator{ MemoryManager::GetSingleton().GetThreadScrapHeap() };  // 00 (20)
		std::byte* _entries{ nullptr };                                               // 08 (28)
	};
}
