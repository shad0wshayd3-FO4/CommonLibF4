#pragma once

namespace RE
{
	namespace PlayerAddicted
	{
		class Event
		{
		public:
			// members
			const AlchemyItem* chem;  // 00
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
