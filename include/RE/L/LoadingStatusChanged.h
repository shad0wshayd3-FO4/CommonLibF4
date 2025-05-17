#pragma once

namespace RE
{
	namespace LoadingStatusChanged
	{
		class Event
		{
		public:
			bool isLoading;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
