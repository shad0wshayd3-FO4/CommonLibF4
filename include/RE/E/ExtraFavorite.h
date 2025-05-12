#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraFavorite :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraFavorite };
		static constexpr auto VTABLE{ VTABLE::ExtraFavorite };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kFavorite };

		// members
		std::int8_t quickkeyIndex;  //18
	};
	static_assert(sizeof(ExtraFavorite) == 0x20);
}
