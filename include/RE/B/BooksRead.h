#pragma once

namespace RE
{
	namespace BooksRead
	{
		class Event
		{
		public:
			// members
			const TESObjectBOOK* book;
			bool                 advancedActorValue;
			bool                 addedPerk;
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
