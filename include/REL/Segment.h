#pragma once

namespace REL
{
	class Segment
	{
	public:
		enum Name : std::size_t
		{
			text,
			interpr,
			idata,
			rdata,
			data,
			pdata,
			tls,
			total
		};

		constexpr Segment() noexcept = default;

		constexpr Segment(std::uintptr_t a_proxyBase, std::uintptr_t a_address, std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase),
			_address(a_address),
			_size(a_size)
		{}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _address; }
		[[nodiscard]] constexpr std::size_t    offset() const noexcept { return address() - _proxyBase; }
		[[nodiscard]] constexpr std::size_t    size() const noexcept { return _size; }

		[[nodiscard]] void* pointer() const noexcept { return reinterpret_cast<void*>(address()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		std::uintptr_t _proxyBase{ 0 };
		std::uintptr_t _address{ 0 };
		std::size_t    _size{ 0 };
	};
}
