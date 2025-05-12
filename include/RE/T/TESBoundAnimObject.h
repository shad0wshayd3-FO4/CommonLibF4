#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class __declspec(novtable) TESBoundAnimObject :
		public TESBoundObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESBoundAnimObject };
		static constexpr auto VTABLE{ VTABLE::TESBoundAnimObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };
	};
	static_assert(sizeof(TESBoundAnimObject) == 0x68);
}
