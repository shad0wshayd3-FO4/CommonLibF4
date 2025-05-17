#pragma once

#include "Scaleform/A/AcquireInterface.h"
#include "Scaleform/W/Waitable.h"

namespace Scaleform
{
	class MutexImpl;

	class __declspec(novtable) Mutex :
		public Waitable,         // 00
		public AcquireInterface  // 18
	{
	public:
		// members
		MutexImpl* impl;  // 20
	};
	static_assert(sizeof(Mutex) == 0x28);
}
