#pragma once

#include "Scaleform/G/GFx_ASStringNodeHolder.h"

namespace Scaleform::GFx
{
	class ASConstString :
		public ASStringNodeHolder
	{
	public:
		const char* ToCStr() const noexcept
		{
			return node->data;
		}
	};
	static_assert(sizeof(ASConstString) == 0x08);
}
