#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class __declspec(novtable) BGSDualCastData :
		public TESBoundObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDualCastData };
		static constexpr auto VTABLE{ VTABLE::BGSDualCastData };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDUAL };

		// members
		BGSDualCastDataDEF data;  // 68
	};
	static_assert(sizeof(BGSDualCastData) == 0x98);
}
