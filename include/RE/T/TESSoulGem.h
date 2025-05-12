#pragma once

namespace RE
{
	class __declspec(novtable) TESSoulGem :
		public TESObjectMISC  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESSoulGem };
		static constexpr auto VTABLE{ VTABLE::TESSoulGem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSLGM };

		// members
		TESSoulGem* linkedSoulGem;  // 168
		std::int8_t currentSoul;    // 170
		std::int8_t soulCapacity;   // 171
	};
	static_assert(sizeof(TESSoulGem) == 0x178);
}
