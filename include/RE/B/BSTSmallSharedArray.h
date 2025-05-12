#pragma once

namespace RE
{
	template <class T>
	class BSTSmallSharedArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = pointer;
		using const_iterator = const_pointer;

		~BSTSmallSharedArray() { stl::report_and_fail("unimplemented"sv); }

		[[nodiscard]] reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] pointer data() noexcept
		{
			return size() > 1 ? heap : std::addressof(local);
		}

		[[nodiscard]] const_pointer data() const noexcept
		{
			return size() > 1 ? heap : std::addressof(local);
		}

		[[nodiscard]] iterator       begin() noexcept { return data(); }
		[[nodiscard]] const_iterator begin() const noexcept { return data(); }
		[[nodiscard]] const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] iterator       end() noexcept { return data() + size(); }
		[[nodiscard]] const_iterator end() const noexcept { return data() + size(); }
		[[nodiscard]] const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] bool empty() const noexcept { return size() != 0; }

		[[nodiscard]] size_type size() const noexcept { return _size; }

	private:
		// members
		std::uint32_t _size{ 0 };  // 00
		union
		{
			pointer    heap{ 0 };
			value_type local;
		};  // 08
	};
}
