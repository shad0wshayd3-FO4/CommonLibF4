#pragma once

namespace RE
{
	namespace HourPassed
	{
		struct Event
		{
		};
		static_assert(std::is_empty_v<Event>);
	}
}
