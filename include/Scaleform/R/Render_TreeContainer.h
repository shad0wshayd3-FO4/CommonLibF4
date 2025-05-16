#pragma once

#include "Scaleform/R/Render_TreeNode.h"

namespace Scaleform::Render
{
	class TreeContainer :
		public TreeNode  // 00
	{
	public:
	};
	static_assert(sizeof(TreeContainer) == 0x38);
}
