#pragma once

#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkCriticalSection.h"

namespace RE
{
	class hknpThreadSafetyCheck
	{
	public:
		struct State
		{
			std::uint32_t numReaders: 5;
			std::uint32_t numWriters: 3;
			std::uint32_t writerThreadId: 24;
		};

		// members
		State             state;
		hkCriticalSection criticalSection;
		hkBool            enabled;
	};
	static_assert(sizeof(hknpThreadSafetyCheck) == 0x38);
}
