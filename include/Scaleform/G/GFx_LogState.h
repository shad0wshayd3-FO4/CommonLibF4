#pragma once

#include "Scaleform/G/GFx_LogBase.h"
#include "Scaleform/G/GFx_State.h"
#include "Scaleform/L/Log.h"
#include "Scaleform/P/Ptr.h"

namespace Scaleform::GFx
{
	class LogState :
		public State,             // 00
		public LogBase<LogState>  // 18
	{
	public:
		// members
		Scaleform::Ptr<Log> log;  // 20
	};
	static_assert(sizeof(LogState) == 0x28);
}
