#pragma once

#include "RE/S/SFRenderContainers.h"
#include "RE/S/SFRenderContext.h"

namespace RE::Scaleform::Render
{
	class TreeContainer;
	class TreeNode;
	class TreeRoot;

	class TreeNode :
		public Context::Entry  // 00
	{
	public:
	};
	static_assert(sizeof(TreeNode) == 0x38);

	class TreeContainer :
		public TreeNode  // 00
	{
	public:
	};
	static_assert(sizeof(TreeContainer) == 0x38);

	class TreeRoot :
		public TreeContainer
	{
	public:
	};
	static_assert(sizeof(TreeRoot) == 0x38);
}
