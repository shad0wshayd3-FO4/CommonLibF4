#pragma once

#include "RE/NetImmerse/NiPoint.h"

namespace RE::HUDMenuUtils
{
	inline void WorldPtToScreenPt3(const NiPoint3& a_world, NiPoint3& a_screen)
	{
		using func_t = void(*)(const NiPoint3&, NiPoint3&);
		static REL::Relocation<func_t> func{ REL::ID(2222464) };
		func(a_world, a_screen);
	}

	inline NiPoint3 WorldPtToScreenPt3(const NiPoint3& a_world)
	{
		NiPoint3 screen;
		WorldPtToScreenPt3(a_world, screen);
		return screen;
	}
}
