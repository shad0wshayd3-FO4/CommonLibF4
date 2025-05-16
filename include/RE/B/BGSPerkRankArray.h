#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class PerkRankData;

	class __declspec(novtable) BGSPerkRankArray :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPerkRankArray };
		static constexpr auto VTABLE{ VTABLE::BGSPerkRankArray };

		virtual ~BGSPerkRankArray()  // 00
		{
			ClearPerks(false);
		}

		// override
		virtual void InitializeDataComponent() override;                 // 02
		virtual void ClearDataComponent() override;                      // 03
		virtual void InitComponent() override;                           // 04
		virtual void CopyComponent(BaseFormComponent* a_copy) override;  // 06

		void AllocatePerkRankArray(std::uint32_t a_count)
		{
			using func_t = decltype(&BGSPerkRankArray::AllocatePerkRankArray);
			static REL::Relocation<func_t> func{ REL::ID(888419) };
			return func(this, a_count);
		}

		void ClearPerks(bool a_removeFormUser)
		{
			using func_t = decltype(&BGSPerkRankArray::ClearPerks);
			static REL::Relocation<func_t> func{ REL::ID(1247917) };
			return func(this, a_removeFormUser);
		}

		// members
		PerkRankData* perks;      // 08
		std::uint32_t perkCount;  // 10
	};
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
