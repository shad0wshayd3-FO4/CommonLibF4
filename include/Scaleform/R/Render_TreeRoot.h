#pragma once

#include "Scaleform/R/Render_TreeContainer.h"

namespace Scaleform::Render
{
	class TreeRoot :
		public TreeContainer
	{
	public:
	};
	static_assert(sizeof(TreeRoot) == 0x38);
}
