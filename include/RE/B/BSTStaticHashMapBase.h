#pragma once

namespace RE
{
    template <std::uint32_t N>
	struct BSTStaticHashMapBase
	{
	public:
		static_assert(N > 0 && std::has_single_bit(N));

		template <std::size_t S, std::size_t A>
		struct Allocator
		{
		public:
			using size_type = std::uint32_t;
			using propagate_on_container_move_assignment = std::false_type;

			Allocator() = default;
			Allocator(const Allocator&) = delete;
			Allocator(Allocator&&) = delete;
			~Allocator() = default;
			Allocator& operator=(const Allocator&) = delete;
			Allocator& operator=(Allocator&&) = delete;

			[[nodiscard]] static constexpr size_type min_size() noexcept { return N; }

			[[nodiscard]] void* allocate_bytes(std::size_t a_bytes)
			{
				assert(a_bytes % S == 0);
				return a_bytes <= N * S ? _buffer : nullptr;
			}

			void deallocate_bytes([[maybe_unused]] void* a_ptr) { assert(a_ptr == _buffer); }

			[[nodiscard]] void* get_entries() const noexcept { return _entries; }

			void set_entries(void* a_entries) noexcept
			{
				assert(a_entries == _buffer || a_entries == nullptr);
				_entries = static_cast<std::byte*>(a_entries);
			}

		private:
			alignas(A) std::byte _buffer[N * S]{ static_cast<std::byte>(0) };  // 00 (20)
			std::byte* _entries{ nullptr };                                    // ??
		};
	};
}
