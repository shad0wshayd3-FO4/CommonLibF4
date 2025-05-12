#pragma once

namespace RE
{
	template <class T>
	class BSStaticArray
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

		[[nodiscard]] reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}

		[[nodiscard]] const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}

		[[nodiscard]] reference       front() noexcept { return operator[](0); }
		[[nodiscard]] const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] reference       back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] pointer       data() noexcept { return _data; }
		[[nodiscard]] const_pointer data() const noexcept { return _data; }

		[[nodiscard]] iterator       begin() noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] const_iterator begin() const noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] iterator       end() noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] const_iterator end() const noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] size_type size() const noexcept { return _size; }

	private:
		// members
		pointer       _data{ nullptr };  // 00
		std::uint32_t _size{ 0 };        // 08
	};
}
