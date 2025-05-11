#pragma once

#include "RE/Bethesda/TESObjectREFRs.h"

namespace RE
{
	namespace PipboyInventoryUtils
	{
		inline bool DoSlotsOverlap(const TESObjectARMO* a_armor1, const TESObjectARMO* a_armor2)
		{
			using func_t = decltype(&DoSlotsOverlap);
			static REL::Relocation<func_t> func{ REL::ID(1035436) };
			return func(a_armor1, a_armor2);
		}

		inline void FillDamageTypeInfo(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack, BSScrapArray<BSTTuple<std::uint32_t, float>>& a_damageValuesPerType)
		{
			using func_t = decltype(&FillDamageTypeInfo);
			static REL::Relocation<func_t> func{ REL::ID(928518) };
			return func(a_item, a_stack, a_damageValuesPerType);
		}

		inline void FillResistTypeInfo(const BGSInventoryItem& a_item, const BGSInventoryItem::Stack* a_stack, BSScrapArray<BSTTuple<std::uint32_t, float>>& a_resistValuesPerType, float a_scale)
		{
			using func_t = decltype(&FillResistTypeInfo);
			static REL::Relocation<func_t> func{ REL::ID(1578434) };
			return func(a_item, a_stack, a_resistValuesPerType, a_scale);
		}
	}
}
