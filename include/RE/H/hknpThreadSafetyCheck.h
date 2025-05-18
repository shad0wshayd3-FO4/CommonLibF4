#pragma once

#include "RE/H/hkBool.h"
#include "RE/H/hkCriticalSection.h"

namespace RE
{
	class hknpThreadSafetyCheck
	{
	public:
		class State
		{
		public:
			// members
			std::uint32_t numReaders: 5;
			std::uint32_t numWriters: 3;
			std::uint32_t writerThreadId: 24;
		};
		static_assert(sizeof(State) == 0x04);

		// members
		State             state;            // 00
		hkCriticalSection criticalSection;  // 08
		hkBool            enabled;          // 30
	};
	static_assert(sizeof(hknpThreadSafetyCheck) == 0x38);
}
