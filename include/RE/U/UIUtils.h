#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	namespace UIUtils
	{
		using ComparisonItems = BSScrapArray<BSTTuple<const BGSInventoryItem*, std::uint32_t>>;

		inline void GetComparisonItems(const TESBoundObject* a_object, ComparisonItems& a_comparisonItems)
		{
			using func_t = decltype(&GetComparisonItems);
			static REL::Relocation<func_t> func{ REL::ID(593818) };
			return func(a_object, a_comparisonItems);
		}

		inline void PlayPipboySound(const char* a_soundName)
		{
			using func_t = decltype(&PlayPipboySound);
			static REL::Relocation<func_t> func{ REL::ID(2249706) };
			return func(a_soundName);
		}

		inline void PlayMenuSound(const char* a_soundName)
		{
			using func_t = decltype(&PlayMenuSound);
			static REL::Relocation<func_t> func{ REL::ID(2249707) };
			return func(a_soundName);
		}

		inline void UpdateGamepadDependentButtonCodes(bool a_usingGamepad)
		{
			using func_t = decltype(&UpdateGamepadDependentButtonCodes);
			static REL::Relocation<func_t> func{ REL::ID(190238) };
			return func(a_usingGamepad);
		}
	}
}
