#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) alignas(0x08) MemoryContext :
		public RefCountBase<MemoryContext, 2>  // 00
	{
	public:
		virtual ~MemoryContext() = default;
	};
	static_assert(sizeof(MemoryContext) == 0x10);
}
