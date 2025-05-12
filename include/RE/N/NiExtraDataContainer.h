#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class NiExtraData;

	class NiExtraDataContainer :
		public BSTArray<NiExtraData*>
	{
	public:
		BSAutoLock<BSSpinLock, BSAutoLockDefaultPolicy> lock;
	};
}
