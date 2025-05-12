#pragma once

namespace RE
{
	template <std::uint32_t FREE_LIST_BITS, std::uint32_t AGE_SHIFT>
	class BSUntypedPointerHandle
	{
	public:
		using HandleType = std::uint32_t;

		enum : std::uint32_t
		{
			kFreeListBits = FREE_LIST_BITS,
			kAgeShift = AGE_SHIFT,
		};

		BSUntypedPointerHandle() noexcept = default;
		BSUntypedPointerHandle(const BSUntypedPointerHandle&) noexcept = default;

		explicit BSUntypedPointerHandle(HandleType a_handle) noexcept :
			_handle(a_handle)
		{}

		~BSUntypedPointerHandle() noexcept { reset(); }

		BSUntypedPointerHandle& operator=(const BSUntypedPointerHandle&) noexcept = default;

		BSUntypedPointerHandle& operator=(HandleType a_rhs) noexcept
		{
			_handle = a_rhs;
			return *this;
		}

		[[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
		[[nodiscard]] bool     has_value() const noexcept { return _handle != 0; }

		[[nodiscard]] HandleType value() const noexcept { return _handle; }

		void reset() noexcept { _handle = 0; }

		[[nodiscard]] friend bool operator==(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs) noexcept
		{
			return a_lhs.value() == a_rhs.value();
		}

	private:
		// members
		HandleType _handle{ 0 };  // 0
	};

	extern template class BSUntypedPointerHandle<>;
}
