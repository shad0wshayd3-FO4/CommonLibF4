#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSCollisionLayer :
		public TESForm,        // 00
		public TESDescription  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSCollisionLayer };
		static constexpr auto VTABLE{ VTABLE::BGSCollisionLayer };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCOLL };

		// members
		std::uint32_t                collisionIdx;  // 38
		std::uint32_t                debugColor;    // 3C
		std::uint32_t                flags;         // 40
		BSFixedString                name;          // 48
		BSTArray<BGSCollisionLayer*> collidesWith;  // 50
	};
	static_assert(sizeof(BGSCollisionLayer) == 0x68);
}
