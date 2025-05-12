#pragma once

namespace RE
{
	class BSTArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using propagate_on_container_move_assignment = std::true_type;

		BSTArrayHeapAllocator() noexcept = default;
		BSTArrayHeapAllocator(const BSTArrayHeapAllocator&) = delete;

		BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs) noexcept :
			_data{ std::exchange(a_rhs._data, nullptr) },
			_capacity{ std::exchange(a_rhs._capacity, 0) }
		{}

		~BSTArrayHeapAllocator() noexcept = default;

		BSTArrayHeapAllocator& operator=(const BSTArrayHeapAllocator&) = delete;

		BSTArrayHeapAllocator& operator=(BSTArrayHeapAllocator&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_data = std::exchange(a_rhs._data, nullptr);
				_capacity = std::exchange(a_rhs._capacity, 0);
			}
			return *this;
		}

		[[nodiscard]] void* allocate(uint32_t a_bytes) { return malloc(a_bytes); }
		void                deallocate(void* a_ptr) { free(a_ptr); }

		[[nodiscard]] void*       data() noexcept { return _data; }
		[[nodiscard]] const void* data() const noexcept { return _data; }
		void                      set_data(void* a_data) noexcept { _data = a_data; }

		[[nodiscard]] size_type capacity() const noexcept { return _capacity; }
		void                    set_capacity(size_type a_capacity, size_type) noexcept { _capacity = a_capacity; }

	private:
		// members
		void*     _data{ nullptr };  // 00
		size_type _capacity{ 0 };    // 08
	};
}
