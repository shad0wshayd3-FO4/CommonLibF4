#pragma once

#include "Scaleform/G/GFx_AS3_GASRefCountBase.h"

namespace Scaleform::GFx::AS3
{
	class VM;

	class __declspec(novtable) VMFile :
		public GASRefCountBase
	{
	public:
		// members
		VM*       vmRef;               // 28
		std::byte pad30[0x98 - 0x30];  // 30
	};
	static_assert(sizeof(VMFile) == 0x98);
}
