#pragma once

namespace RE
{
	class BSIntrusiveRefCounted
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIntrusiveRefCounted };

		constexpr BSIntrusiveRefCounted() noexcept {}  // NOLINT(modernize-use-equals-default)

		[[nodiscard]] std::uint32_t DecRef() const
		{
			stl::atomic_ref myRefCount{ refCount };
			return --myRefCount;
		}

		std::uint32_t IncRef() const
		{
			stl::atomic_ref myRefCount{ refCount };
			return ++myRefCount;
		}

		[[nodiscard]] constexpr std::uint32_t QRefCount() const noexcept { return refCount; }

		// members
		mutable std::uint32_t refCount{ 0 };  // 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x4);
}
