#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::Render
{
	class __declspec(novtable) ThreadCommand :
		public RefCountBase<ThreadCommand, 2>  // 00
	{
	public:
		// add
		virtual void Execute() = 0;  // 01
	};
	static_assert(sizeof(ThreadCommand) == 0x10);
}
