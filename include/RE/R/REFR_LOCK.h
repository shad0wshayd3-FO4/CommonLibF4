#pragma once

namespace RE
{
	class REFR_LOCK
	{
	public:
		[[nodiscard]] LOCK_LEVEL GetLockLevel(TESObjectREFR* a_owner)
		{
			using func_t = decltype(&REFR_LOCK::GetLockLevel);
			static REL::Relocation<func_t> func{ REL::ID(2191018) };
			return func(this, a_owner);
		}

		void SetLocked(bool a_locked)
		{
			using func_t = decltype(&REFR_LOCK::SetLocked);
			static REL::Relocation<func_t> func{ REL::ID(2191020) };
			return func(this, a_locked);
		}

		bool IsBroken()
		{
			using func_t = decltype(&REFR_LOCK::IsBroken);
			static REL::Relocation<func_t> func{ REL::ID(2191021) };
			return func(this);
		}

		// members
		std::uint8_t  baseLevel;  // 00
		TESKey*       key;        // 08
		std::uint8_t  flags;      // 10
		std::uint32_t numTries;   // 14
	};
	static_assert(sizeof(REFR_LOCK) == 0x18);
}
