#pragma once

namespace RE
{
	namespace HourPassed
	{
		class Event
		{
		public:
		};
		static_assert(std::is_empty_v<Event>);
	}
}
