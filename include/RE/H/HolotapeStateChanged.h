#pragma once

namespace RE
{
	namespace HolotapeStateChanged
	{
		struct Event
		{
		};
		static_assert(std::is_empty_v<Event>);
	}
}
