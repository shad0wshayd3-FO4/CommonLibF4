#pragma once

#include "Scaleform/G/GFx_AS3_RefCountBaseGC.h"

namespace Scaleform::GFx::AS3
{
	class __declspec(novtable) GASRefCountBase :
		public RefCountBaseGC<328>  // 00
	{
	public:
	};
	static_assert(sizeof(GASRefCountBase) == 0x28);
}
