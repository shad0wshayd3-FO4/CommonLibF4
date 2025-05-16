#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	struct MapMarkerData;

	class __declspec(novtable) ExtraMapMarker :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraMapMarker };
		static constexpr auto VTABLE{ VTABLE::ExtraMapMarker };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kMapMarker };

		// members
		MapMarkerData* mapMarkerData;  // 18
	};
	static_assert(sizeof(ExtraMapMarker) == 0x20);
}
