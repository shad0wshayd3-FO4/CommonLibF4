#pragma once

#include "Scaleform/G/GFx_ASStringNode.h"

namespace Scaleform::GFx
{
	class ASStringNodeHolder
	{
	public:
		// members
		ASStringNode* node;  // 00
	};
	static_assert(sizeof(ASStringNodeHolder) == 0x08);
}
