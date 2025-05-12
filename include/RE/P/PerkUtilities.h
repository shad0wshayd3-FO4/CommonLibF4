#pragma once

namespace RE
{
	namespace PerkUtilities
	{
		inline void RemoveGrenadeTrajectory()
		{
			using func_t = decltype(&RemoveGrenadeTrajectory);
			static REL::Relocation<func_t> func{ REL::ID(672186) };
			return func();
		}
	}
}
