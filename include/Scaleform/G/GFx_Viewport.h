#pragma once

#include "Scaleform/R/Render_Viewport.h"

namespace Scaleform::GFx
{
	class Viewport :
		public Render::Viewport
	{
	public:
		// members
		float scale;        // 2C
		float aspectRatio;  // 30
	};
	static_assert(sizeof(Viewport) == 0x34);
}
