#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSThread.h"
#include "RE/Bethesda/Events.h"

namespace RE
{
	namespace BSSaveDataSystemUtility
	{
		enum class RESULT
		{
			kSuccess = 0x0,
			kCancel = 0x1,
			kFailed = 0x2,
		};
	}
}
