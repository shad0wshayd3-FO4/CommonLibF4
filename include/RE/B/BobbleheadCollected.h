#pragma once

namespace RE
{
	namespace BobbleheadCollected
	{
		struct Event
		{
		};
		static_assert(std::is_empty_v<Event>);
	}
}
