#pragma once

namespace RE
{
	namespace LocationMarkerArrayUpdate
	{
		class Event
		{
		public:
			bool shouldClearMapMarkers;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
