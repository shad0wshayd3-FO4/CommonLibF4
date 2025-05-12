#pragma once

namespace RE
{
	class BSCriticalSection
	{
	public:
		// members
		REX::W32::CRITICAL_SECTION criticalSection;  // 00
	};
	static_assert(sizeof(BSCriticalSection) == 0x28);
}
