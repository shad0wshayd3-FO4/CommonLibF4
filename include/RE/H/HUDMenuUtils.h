#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	namespace HUDMenuUtils
	{
		inline NiColor GetGameplayHUDColor()
		{
			using func_t = decltype(&HUDMenuUtils::GetGameplayHUDColor);
			static REL::Relocation<func_t> func{ ID::HUDMenuUtils::GetGameplayHUDColor };
			return func();
		}

		inline NiColor GetGameplayHUDBackgroundColor()
		{
			using func_t = decltype(&HUDMenuUtils::GetGameplayHUDBackgroundColor);
			static REL::Relocation<func_t> func{ ID::HUDMenuUtils::GetGameplayHUDBackgroundColor };
			return func();
		}

		inline void WorldPtToScreenPt3(const NiPoint3& a_world, NiPoint3& a_screen)
		{
			using func_t = void (*)(const NiPoint3&, NiPoint3&);
			static REL::Relocation<func_t> func{ ID::HUDMenuUtils::WorldPtToScreenPt3 };
			func(a_world, a_screen);
		}

		inline NiPoint3 WorldPtToScreenPt3(const NiPoint3& a_world)
		{
			NiPoint3 screen;
			WorldPtToScreenPt3(a_world, screen);
			return screen;
		}
	}
}
