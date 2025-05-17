#pragma once

namespace RE
{
	namespace CustomMarkerUpdate
	{
		class Event
		{
		public:
		};
		static_assert(std::is_empty_v<Event>);
	}
}
