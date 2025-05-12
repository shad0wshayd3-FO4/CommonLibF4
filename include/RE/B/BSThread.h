#pragma once

namespace RE
{
	class BSThread
	{
	public:
		virtual ~BSThread();  // 00

		// add
		virtual std::uint32_t ThreadProc();  // 01

		// members
		REX::W32::CRITICAL_SECTION criticalSection;  // 08
		void*                      threadHandle;     // 30
		void*                      parentHandle;     // 38
		std::uint32_t              threadID;         // 40
		std::uint32_t              parentID;         // 44
		volatile bool              threadIsActive;   // 48
	};
	static_assert(sizeof(BSThread) == 0x50);
}
