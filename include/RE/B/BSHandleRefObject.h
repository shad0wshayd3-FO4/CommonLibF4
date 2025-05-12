#pragma once

namespace RE
{
	class __declspec(novtable) BSHandleRefObject :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSHandleRefObject };
		static constexpr auto VTABLE{ VTABLE::BSHandleRefObject };

		std::uint32_t DecRefCount()
		{
			stl::atomic_ref myRefCount{ refCount };
			const auto      newRefCount = --myRefCount & 0x3FF;
			if (newRefCount == 0) {
				DeleteThis();
			}
			return newRefCount;
		}

		void IncRefCount()
		{
			stl::atomic_ref myRefCount{ refCount };
			++myRefCount;
		}

		[[nodiscard]] std::uint32_t QRefCount() const noexcept { return refCount & 0x3FF; }
	};
	static_assert(sizeof(BSHandleRefObject) == 0x10);
}
