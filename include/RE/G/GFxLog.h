#pragma once

#include "RE/G/GFxLoader.h"
#include "RE/S/SFLog.h"

namespace RE::Scaleform::GFx
{
	using Log = Scaleform::Log;

	template <class T>
	class __declspec(novtable) LogBase
	{
	public:
		virtual ~LogBase();  // 00

		// add
		virtual bool IsVerboseActionErrors();  // 01
	};

	class LogState :
		public State,             // 00
		public LogBase<LogState>  // 18
	{
	public:
		// members
		Scaleform::Ptr<Scaleform::Log> log;  // 20
	};
	static_assert(sizeof(LogState) == 0x28);
}
