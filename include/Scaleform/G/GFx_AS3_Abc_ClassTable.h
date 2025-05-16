#pragma once

#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3::Abc
{
	class ClassTable :
		public NewOverrideBase<338>
	{
	public:
		// members
		std::byte pad[0x18 - 0x00];  // 00
	};
	static_assert(sizeof(ClassTable) == 0x18);
}
