#pragma once

#include "Scaleform/R/Render_ContextImpl_RTHandle.h"

namespace Scaleform::Render::ContextImpl
{
	template <class C>
	class DisplayHandle :
		public RTHandle  // 0
	{
	public:
	};
	//static_assert(sizeof(DisplayHandle<void*>) == 0x8);
}
