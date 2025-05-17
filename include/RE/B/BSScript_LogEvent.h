#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_ErrorLogger.h"
#include "RE/B/BSScript_ICachedErrorMessage.h"

namespace RE
{
	namespace BSScript
	{
		class LogEvent
		{
		public:
			const ICachedErrorMessage&  errorMsg;     // 00
			const ErrorLogger::Severity severity;     // 08
			std::uint32_t               pad0C;        // 0C
			BSFixedString               ownerModule;  // 10
		};
		static_assert(sizeof(LogEvent) == 0x18);
	}
}
