#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform
{
	class LogMessageId;

	class __declspec(novtable) alignas(0x08) Log :
		public RefCountBase<Log, 2>  // 00
	{
	public:
		static constexpr auto RTTI{ RE::RTTI::Scaleform__Log };
		static constexpr auto VTABLE{ RE::VTABLE::Scaleform__Log };

		virtual ~Log()
		{
			Release();
		}

		// add
		virtual void LogMessageVarg(LogMessageId a_messageID, const char* a_fmt, std::va_list a_argList);
	};
	static_assert(sizeof(Log) == 0x10);
}
