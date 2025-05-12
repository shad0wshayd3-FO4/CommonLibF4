#pragma once

namespace RE
{
	namespace LocationMarkerArrayUpdate
	{
		struct Event
		{
			bool shouldClearMapMarkers;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
