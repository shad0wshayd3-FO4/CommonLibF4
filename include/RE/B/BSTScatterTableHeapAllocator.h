#pragma once

namespace RE
{
    template <std::size_t S, std::size_t A>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using propagate_on_container_move_assignment = std::true_type;

		BSTScatterTableHeapAllocator() = default;
		BSTScatterTableHeapAllocator(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator(BSTScatterTableHeapAllocator&& a_rhs) noexcept :
			_entries(std::exchange(a_rhs._entries, nullptr))
		{}

		~BSTScatterTableHeapAllocator() = default;
		BSTScatterTableHeapAllocator& operator=(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator& operator=(BSTScatterTableHeapAllocator&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				assert(_entries == nullptr);
				_entries = std::exchange(a_rhs._entries, nullptr);
			}
			return *this;
		}

		[[nodiscard]] static constexpr size_type min_size() noexcept { return 1u << 3; }

		[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
		{
			assert(a_bytes % S == 0);
			return malloc(a_bytes);
		}

		void deallocate_bytes(void* a_ptr) { free(a_ptr); }

		[[nodiscard]] void* get_entries() const noexcept { return _entries; }
		void                set_entries(void* a_entries) noexcept { _entries = static_cast<std::byte*>(a_entries); }

	private:
		// members
		std::uint64_t _pad00{ 0 };          // 00 (20)
		std::byte*    _entries{ nullptr };  // 08 (28)
	};

}
