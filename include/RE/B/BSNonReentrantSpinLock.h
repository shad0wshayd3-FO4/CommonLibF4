#pragma once

namespace RE
{
	class BSNonReentrantSpinLock
	{
	public:
		constexpr BSNonReentrantSpinLock() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		std::uint32_t lock{ 0 };  // 0
	};
	static_assert(sizeof(BSNonReentrantSpinLock) == 0x4);
}
