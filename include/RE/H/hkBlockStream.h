#pragma once

#include "RE/H/hkBlockStreamBase.h"

namespace RE
{
	template <class T>
	class hkBlockStream :
		public hkBlockStreamBase::Stream
	{
	public:
	};
	static_assert(sizeof(hkBlockStream<void>) == 0x100);
}
