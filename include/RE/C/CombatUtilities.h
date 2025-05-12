#pragma once

namespace RE
{
	namespace CombatUtilities
	{
		inline bool CalculateProjectileLOS(
			Actor*          a_actor,
			BGSProjectile*  a_projectile,
			float           a_projectileSpeed,
			const NiPoint3& a_launchPos,
			const NiPoint3& a_targetPos,
			NiPoint3*       a_hitPos,
			TESObjectREFR** a_collidee,
			float*          a_distanceFraction)
		{
			using func_t = bool (*)(Actor*, BGSProjectile*, float, const NiPoint3&, const NiPoint3&, NiPoint3*, TESObjectREFR**, float*);
			static REL::Relocation<func_t> func{ REL::ID(798616) };
			return func(a_actor, a_projectile, a_projectileSpeed, a_launchPos, a_targetPos, a_hitPos, a_collidee, a_distanceFraction);
		}

		inline bool CalculateProjectileLOS(Actor* a_actor, BGSProjectile* a_projectile, bhkPickData& a_pickData)
		{
			using func_t = bool (*)(Actor*, BGSProjectile*, bhkPickData&);
			static REL::Relocation<func_t> func{ REL::ID(55339) };
			return func(a_actor, a_projectile, a_pickData);
		}

		inline bool CalculateProjectileTrajectory(
			const NiPoint3& a_projectilePos,
			const NiPoint3& a_projectileVelocity,
			float           a_projectileGravity,
			const NiPoint3& a_targetPos,
			float           a_heading,
			NiPoint3&       a_trajectoryPos)
		{
			using func_t = decltype(&CalculateProjectileTrajectory);
			static REL::Relocation<func_t> func{ REL::ID(1575156) };
			return func(a_projectilePos, a_projectileVelocity, a_projectileGravity, a_targetPos, a_heading, a_trajectoryPos);
		}

		static REL::Relocation<float> fWorldGravity{ REL::ID(1378547) };
	}
}
