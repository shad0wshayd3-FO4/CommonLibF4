#pragma once

#include "RE/B/BSResource_FileID.h"

namespace RE::BSResource
{
	struct ID :
		public FileID  // 0
	{
	public:
		[[nodiscard]] bool operator==(const ID&) const noexcept = default;

		// members
		std::uint32_t dir = 0;  // 8
	};
	static_assert(sizeof(ID) == 0xC);
}
