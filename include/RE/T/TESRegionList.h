#pragma once

#include "RE/B/BSSimpleList.h"

namespace RE
{
	class __declspec(novtable) TESRegionList :
		public BSSimpleList<TESRegion*>
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRegionList };
		static constexpr auto VTABLE{ VTABLE::TESRegionList };

		virtual ~TESRegionList();  // 00

		// members
		bool          ownsRegionMemory;  // 18
		std::uint8_t  pad19;             // 19
		std::uint16_t pad1A;             // 1A
		std::uint32_t pad1C;             // 1C
	};
	static_assert(sizeof(TESRegionList) == 0x20);
}
