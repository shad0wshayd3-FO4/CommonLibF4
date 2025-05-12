#pragma once

namespace RE
{
	namespace CustomMarkerUpdate
	{
		struct Event
		{
		};
		static_assert(std::is_empty_v<Event>);
	}
}
