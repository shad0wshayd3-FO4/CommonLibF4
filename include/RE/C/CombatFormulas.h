#pragma once

namespace RE
{
	class Actor;

	namespace CombatFormulas
	{
		[[nodiscard]] inline float GetWeaponDisplayAccuracy(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, Actor* a_actor)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayAccuracy);
			static REL::Relocation<func_t> func{ REL::ID(1137654) };
			return func(a_weapon, a_actor);
		}

		[[nodiscard]] inline float GetWeaponDisplayDamage(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, const TESAmmo* a_ammo, float a_condition)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayDamage);
			static REL::Relocation<func_t> func{ REL::ID(1431014) };
			return func(a_weapon, a_ammo, a_condition);
		}

		[[nodiscard]] inline float GetWeaponDisplayRange(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayRange);
			static REL::Relocation<func_t> func{ REL::ID(1324037) };
			return func(a_weapon);
		}

		[[nodiscard]] inline float GetWeaponDisplayRateOfFire(const TESObjectWEAP& a_weapon, const TESObjectWEAP::InstanceData* a_data)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayRateOfFire);
			static REL::Relocation<func_t> func{ REL::ID(1403591) };
			return func(a_weapon, a_data);
		}
	}
}
