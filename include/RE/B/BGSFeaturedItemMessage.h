#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSFeaturedItemMessage :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSFeaturedItemMessage };
		static constexpr auto VTABLE{ VTABLE::BGSFeaturedItemMessage };

		// members
		BGSMessage* featuredItemMessage;  // 08
	};
	static_assert(sizeof(BGSFeaturedItemMessage) == 0x10);
}
