#pragma once

namespace Scaleform
{
	class Lock
	{
	public:
		// members
		REX::W32::CRITICAL_SECTION cs;  // 00
	};
	static_assert(sizeof(Lock) == 0x28);
}
