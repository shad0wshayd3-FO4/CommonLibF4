#pragma once

namespace RE
{
	class NiExtraDataContainer :
		public BSTArray<NiExtraData*>
	{
	public:
		BSAutoLock<BSSpinLock, BSAutoLockDefaultPolicy> lock;
	};
}
