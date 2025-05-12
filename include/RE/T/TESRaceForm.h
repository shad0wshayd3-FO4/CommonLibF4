#pragma once

namespace RE
{
	class __declspec(novtable) TESRaceForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRaceForm };
		static constexpr auto VTABLE{ VTABLE::TESRaceForm };

		// add
		virtual bool SwitchRace(TESRace* a_race)  // 07
		{
			formRace = a_race;
			return true;
		}

		[[nodiscard]] TESRace* GetFormRace() const noexcept { return formRace; }
		void                   SetFormRace(TESRace* a_race) noexcept { formRace = a_race; }

		// members
		TESRace* formRace;  // 08
	};
	static_assert(sizeof(TESRaceForm) == 0x10);

}
