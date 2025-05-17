#pragma once

#include "Scaleform/G/GFx_AS3_VM.h"

namespace Scaleform::GFx::AS3
{
	class __declspec(novtable) ASVM :
		public VM  // 00
	{
	public:
		// members
		std::byte pad2D0[0x3C8 - 0x2D0];  // 2D0
	};
	static_assert(sizeof(ASVM) == 0x3C8);
}
