#pragma once

namespace RE
{
	class hkCriticalSection
	{
	public:
		// members
		REX::W32::CRITICAL_SECTION section;  // 00
	};
	static_assert(sizeof(hkCriticalSection) == 0x28);
}
