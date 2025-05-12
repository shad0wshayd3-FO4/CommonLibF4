#pragma once

namespace RE
{
	namespace BooksRead
	{
		struct Event
		{
			// members
			const TESObjectBOOK* book;
			bool                 advancedActorValue;
			bool                 addedPerk;
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
