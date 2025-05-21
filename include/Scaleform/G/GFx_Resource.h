#pragma once

#include "Scaleform/A/Atomic.h"
#include "Scaleform/G/GFx_ResourceLibBase.h"
#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx
{
	class ResourceKey;
	class ResourceReport;

	class __declspec(novtable) Resource :
		public NewOverrideBase<2>  // 00
	{
	public:
		virtual ~Resource() = default;  // 00

		// add
		virtual ResourceKey     GetKey();                     // 01
		virtual std::uint32_t   GetResourceTypeCode() const;  // 02
		virtual ResourceReport* GetResourceReport();          // 03

		void AddRef()
		{
			REX::TAtomicRef myRefCount{ refCount.value };
			++myRefCount;
		}

		void Release()
		{
			REX::TAtomicRef myRefCount{ refCount.value };
			if (--myRefCount == 0) {
				delete lib;
				lib = nullptr;
				delete this;
			}
		}

		// members
		AtomicInt<std::int32_t> refCount;  // 08
		ResourceLibBase*        lib;       // 10
	};
	static_assert(sizeof(Resource) == 0x18);
}
