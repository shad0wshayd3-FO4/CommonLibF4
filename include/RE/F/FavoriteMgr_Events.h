#pragma once

namespace RE
{
	namespace FavoriteMgr_Events
	{
		class ComponentFavoriteEvent
		{
		public:
			// members
			BGSComponent* component;    // 00
			bool          isFavorited;  // 08
		};
		static_assert(sizeof(ComponentFavoriteEvent) == 0x10);
	}
}
