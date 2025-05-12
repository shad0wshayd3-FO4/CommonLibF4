#pragma once

namespace RE
{
	class __declspec(novtable) TrespassPackage :
		public TESPackage  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TrespassPackage };
		static constexpr auto VTABLE{ VTABLE::TrespassPackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// members
		float        warningtimer;  // C8
		std::int32_t warning;       // CC
		TESForm*     owner;         // D0
		std::int32_t crimeNumber;   // D9
		std::int32_t warninglevel;  // DC
		std::int32_t numberActors;  // E0
	};
	static_assert(sizeof(TrespassPackage) == 0xE8);
}
