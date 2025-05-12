#pragma once

namespace RE
{
	namespace TravelMarkerStateChange
	{
		struct Event
		{
			BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>> markerRef;            // 00
			MapMarkerData*                                                data;                 // 08
			std::uint32_t                                                 selectedMarkerIndex;  // 10
			bool                                                          discovered;           // 14
		};
		static_assert(sizeof(Event) == 0x18);
	}
}
