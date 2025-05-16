#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	struct MapMarkerData;

	namespace TravelMarkerStateChange
	{
		struct Event
		{
			ObjectRefHandle markerRef;            // 00
			MapMarkerData*  data;                 // 08
			std::uint32_t   selectedMarkerIndex;  // 10
			bool            discovered;           // 14
		};
		static_assert(sizeof(Event) == 0x18);
	}
}
