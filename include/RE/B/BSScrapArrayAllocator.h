#pragma once

namespace RE
{
	class BSScrapArrayAllocator
	{
	public:
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using propagate_on_container_move_assignment = std::false_type;

		BSScrapArrayAllocator() noexcept = default;
		BSScrapArrayAllocator(const BSScrapArrayAllocator&) = delete;
		BSScrapArrayAllocator(BSScrapArrayAllocator&&) = delete;

		~BSScrapArrayAllocator() noexcept = default;

		BSScrapArrayAllocator& operator=(const BSScrapArrayAllocator&) = delete;
		BSScrapArrayAllocator& operator=(BSScrapArrayAllocator&&) = delete;

		[[nodiscard]] void* allocate(uint32_t a_bytes)
		{
			if (!_allocator) {
				auto& heap = MemoryManager::GetSingleton();
				_allocator = heap.GetThreadScrapHeap();
			}

			if (!_allocator) {
				stl::report_and_fail("failed to get thread scrap heap"sv);
			}

			const auto mem = _allocator->Allocate(a_bytes, alignof(void*));
			if (!mem) {
				stl::report_and_fail("failed to handle allocation request"sv);
			} else {
				return mem;
			}
		}

		void deallocate(void* a_ptr)
		{
			if (_allocator) {
				_allocator->Deallocate(a_ptr);
			} else {
				stl::report_and_fail("failed to deallocate block"sv);
			}
		}

		[[nodiscard]] void*       data() noexcept { return _data; }
		[[nodiscard]] const void* data() const noexcept { return _data; }
		void                      set_data(void* a_data) noexcept { _data = a_data; }

		[[nodiscard]] size_type capacity() const noexcept { return _capacity; }
		void                    set_capacity(size_type a_capacity, size_type) noexcept { _capacity = a_capacity; }

	private:
		// members
		ScrapHeap* _allocator{ nullptr };  // 00
		void*      _data{ nullptr };       // 08
		size_type  _capacity{ 0 };         // 10
	};
}
