#pragma once

namespace RE
{
	class IsPipboyActiveEvent :
		public BSTValueEvent<bool>  // 00
	{
	public:
	};
	static_assert(sizeof(IsPipboyActiveEvent) == 0x02);
}
