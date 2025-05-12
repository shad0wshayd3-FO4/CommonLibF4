#pragma once

namespace RE
{
	namespace LoadingStatusChanged
	{
		struct Event
		{
			bool isLoading;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
