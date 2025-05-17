#pragma once

#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3::Abc
{
	class MethodBodyTable :
		public NewOverrideBase<338>
	{
	public:
		// members
		std::byte pad[0x18];  // 00
	};
	static_assert(sizeof(MethodBodyTable) == 0x18);
}
