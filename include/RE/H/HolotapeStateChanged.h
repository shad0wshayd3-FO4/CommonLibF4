#pragma once

namespace RE
{
	namespace HolotapeStateChanged
	{
		class Event
		{
		public:
		};
		static_assert(std::is_empty_v<Event>);
	}
}
