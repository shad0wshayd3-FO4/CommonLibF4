#pragma once

#include "Scaleform/G/GFx_ASConstString.h"

namespace Scaleform::GFx
{
	class ASString :
		public ASConstString
	{
	public:
	};
	static_assert(sizeof(ASString) == 0x08);
}
