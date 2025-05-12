#pragma once

namespace RE
{
	template <std::uint32_t N>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using propagate_on_container_move_assignment = std::false_type;

		BSTSmallArrayHeapAllocator() noexcept = default;
		BSTSmallArrayHeapAllocator(const BSTSmallArrayHeapAllocator&) = delete;
		BSTSmallArrayHeapAllocator(BSTSmallArrayHeapAllocator&&) = delete;

		~BSTSmallArrayHeapAllocator() noexcept = default;

		BSTSmallArrayHeapAllocator& operator=(const BSTSmallArrayHeapAllocator&) = delete;
		BSTSmallArrayHeapAllocator& operator=(BSTSmallArrayHeapAllocator&&) = delete;

		[[nodiscard]] void* allocate(uint32_t a_bytes)
		{
			if (a_bytes > N) {
				return malloc(a_bytes);
			} else {
				return _stack;
			}
		}

		void deallocate(void* a_ptr)
		{
			if (a_ptr != _stack) {
				free(a_ptr);
			}
		}

		[[nodiscard]] void*       data() noexcept { return _local ? _stack : _heap; }
		[[nodiscard]] const void* data() const noexcept { return _local ? _stack : _heap; }

		void set_data(void* a_data) noexcept
		{
			if (a_data != _stack) {
				_heap = a_data;
			}
		}

		[[nodiscard]] size_type capacity() const noexcept { return _capacity; }

		void set_capacity(size_type a_capacity, size_type a_bytes) noexcept
		{
			_local = a_bytes <= N ? true : false;
			_capacity = a_capacity;
		}

	private:
		// members
		size_type _capacity: 31 { 0 };  // 00:00
		size_type _local: 1 { 0 };      // 00:31
		union
		{
			void*     _heap{ nullptr };
			std::byte _stack[N];
		};  // 08
	};
}
