#pragma once

namespace RE::BSResource
{
	namespace Archive2
	{
		struct ClearRegistryEvent
		{
		public:
		};
		static_assert(std::is_empty_v<ClearRegistryEvent>);
	}
}
