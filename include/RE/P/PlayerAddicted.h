#pragma once

namespace RE
{
	namespace PlayerAddicted
	{
		struct Event
		{
			const AlchemyItem* chem;
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
