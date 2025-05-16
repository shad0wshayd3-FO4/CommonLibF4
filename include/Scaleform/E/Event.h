#pragma once

#include "Scaleform/W/Waitable.h"
#include "Scaleform/A/AcquireInterface.h"
#include "Scaleform/M/Mutex.h"
#include "Scaleform/W/WaitCondition.h"

namespace Scaleform
{
	class __declspec(novtable) Event :
		public Waitable,         // 00
		public AcquireInterface  // 18
	{
	public:
		// members
		volatile bool state;               // 20
		volatile bool temporary;           // 21
		mutable Mutex stateMutex;          // 28
		WaitCondition stateWaitCondition;  // 50
	};
	static_assert(sizeof(Event) == 0x58);
}
