#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class __declspec(novtable) ExtraPowerLinks :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraPowerLinks };
		static constexpr auto VTABLE{ VTABLE::ExtraPowerLinks };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kPowerLinks };

		class Element
		{
		public:
			// members
			TESFormID     formID;    // 0
			std::uint32_t linkType;  // 4
		};
		static_assert(sizeof(Element) == 0x8);

		// members
		BSTArray<Element> powerLinks;  // 18
	};
	static_assert(sizeof(ExtraPowerLinks) == 0x30);
}
