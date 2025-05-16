#pragma once

#include "Scaleform/M/Memory.h"

namespace Scaleform
{
	class RefCountImplCore
	{
	public:
		static constexpr auto RTTI{ RE::RTTI::Scaleform__RefCountImplCore };
		static constexpr auto VTABLE{ RE::VTABLE::Scaleform__RefCountImplCore };

		RefCountImplCore() = default;
		virtual ~RefCountImplCore() = default;  // 00

	protected:
		// members
		volatile std::int32_t refCount{ 1 };  // 08
	};
	static_assert(sizeof(RefCountImplCore) == 0x10);

	class RefCountImpl :
		public RefCountImplCore  // 00
	{
	public:
		static constexpr auto RTTI{ RE::RTTI::Scaleform__RefCountImpl };
		static constexpr auto VTABLE{ RE::VTABLE::Scaleform__RefCountImpl };

		virtual ~RefCountImpl() = default;  // NOLINT(modernize-use-override) 00

		void AddRef()
		{
			stl::atomic_ref myRefCount{ refCount };
			++refCount;
		}

		void Release()
		{
			stl::atomic_ref myRefCount{ refCount };
			if (--myRefCount == 0) {
				delete this;
			}
		}
	};
	static_assert(sizeof(RefCountImpl) == 0x10);

	template <class Base, std::int32_t>
	class RefCountBaseStatImpl :
		public Base  // 00
	{
	public:
		RefCountBaseStatImpl() = default;

		SF_HEAP_REDEFINE_NEW(RefCountBaseStatImpl);
	};
	//static_assert(sizeof(RefCountBaseStatImpl<void*, 0>) == 0x10);

	template <class, std::int32_t STAT>
	class RefCountBase :
		public RefCountBaseStatImpl<RefCountImpl, STAT>  // 00
	{
	public:
		RefCountBase() = default;
	};
	//static_assert(sizeof(RefCountBase<void*, 0>) == 0x10);
}
