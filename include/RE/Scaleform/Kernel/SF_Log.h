#pragma once

#include "RE/Scaleform/Kernel/SF_RefCount.h"

namespace RE::Scaleform
{
	class Log;
	class LogMessageId;

	class LogMessageId
	{
	public:
		LogMessageId(std::int32_t a_id) :
			id(a_id)
		{}

		~LogMessageId() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		std::int32_t id;  // 0
	};
	static_assert(sizeof(LogMessageId) == 0x4);

	class __declspec(novtable) alignas(0x08) Log :
		public RefCountBase<Log, 2>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Scaleform__Log };
		static constexpr auto VTABLE{ VTABLE::Scaleform__Log };

		virtual ~Log()
		{
			Release();
		}

		// add
		virtual void LogMessageVarg(LogMessageId a_messageID, const char* a_fmt, std::va_list a_argList);
	};
	static_assert(sizeof(Log) == 0x10);
}
