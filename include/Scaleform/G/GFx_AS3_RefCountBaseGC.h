#pragma once

#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3
{
	template <std::int32_t STAT>
	class __declspec(novtable) RefCountBaseGC :
		public NewOverrideBase<STAT>  // 00
	{
	public:
		virtual ~RefCountBaseGC();  // 00

		// members
		union
		{
			void*         rcc;
			std::uint64_t rccRaw;
		};  // 08
		union
		{
			const RefCountBaseGC<STAT>* next;
			const RefCountBaseGC<STAT>* nextRoot;
		};  // 10
		union
		{
			const RefCountBaseGC<STAT>* prev;
			const RefCountBaseGC<STAT>* prevRoot;
		};  // 18
		std::uint32_t refCount;  // 20
	};
	static_assert(sizeof(RefCountBaseGC<328>) == 0x28);
}
