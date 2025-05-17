#pragma once

#include "Scaleform/G/GFx_ASStringBuiltinManagerT.h"

namespace Scaleform::GFx::AS3
{
	enum class BuiltinType;

	class StringManager :
		public ASStringBuiltinManagerT<BuiltinType, 65>
	{
	public:
	};
	static_assert(sizeof(StringManager) == 0x218);
}
