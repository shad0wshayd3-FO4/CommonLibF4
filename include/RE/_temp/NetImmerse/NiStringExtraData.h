#pragma once

#include "RE/NetImmerse/NiExtraData.h"

namespace RE
{
	class NiStringExtraData : public NiExtraData
	{
	public:
		static constexpr auto RTTI{ RTTI::NiStringExtraData };
		static constexpr auto VTABLE{ VTABLE::NiStringExtraData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiStringExtraData };

		// members
		BSFixedString data;  // 18
	};
	static_assert(sizeof(NiStringExtraData) == 0x20);
}
