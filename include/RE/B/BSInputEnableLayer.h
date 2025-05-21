#pragma once

namespace RE
{
	class BSInputEnableLayer
	{
	public:
		constexpr BSInputEnableLayer() noexcept {}  // NOLINT(modernize-use-equals-default)

		[[nodiscard]] std::uint32_t DecRef() const
		{
			using func_t = decltype(&BSInputEnableLayer::DecRef);
			static REL::Relocation<func_t> func{ ID::BSInputEnableLayer::DecRef };
			return func(this);
		}

		std::uint32_t IncRef() const
		{
			REX::TAtomicRef myRefCount{ refCount };
			return ++myRefCount;
		}

		// members
		std::uint32_t         layerID;   // 00
		mutable std::uint32_t refCount;  // 04
	};
	static_assert(sizeof(BSInputEnableLayer) == 0x08);
}
