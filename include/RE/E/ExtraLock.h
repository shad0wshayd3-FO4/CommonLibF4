#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	struct REFR_LOCK;

	class __declspec(novtable) ExtraLock :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLock };
		static constexpr auto VTABLE{ VTABLE::ExtraLock };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLock };

		// members
		REFR_LOCK* lock;  // 18
	};
	static_assert(sizeof(ExtraLock) == 0x20);
}
