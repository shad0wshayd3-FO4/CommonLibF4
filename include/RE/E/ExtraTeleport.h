#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraTeleport :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraTeleport };
		static constexpr auto VTABLE{ VTABLE::ExtraTeleport };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kTeleport };

		// members
		DoorTeleportData* teleportData;  // 18
	};
	static_assert(sizeof(ExtraTeleport) == 0x20);
}
