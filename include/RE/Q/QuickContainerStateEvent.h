#pragma once

namespace RE
{
	class QuickContainerStateEvent :
		public BSTValueEvent<QuickContainerStateData>  // 00
	{
	public:
	};
	static_assert(sizeof(QuickContainerStateEvent) == 0xC0);
}
