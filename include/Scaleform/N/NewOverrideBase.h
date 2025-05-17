#pragma once

#include "Scaleform/M/Memory.h"

namespace Scaleform
{
	template <std::int32_t>
	class NewOverrideBase
	{
	public:
		SF_HEAP_REDEFINE_NEW(NewOverrideBase)
	};
	static_assert(std::is_empty_v<NewOverrideBase<0>>);
}
