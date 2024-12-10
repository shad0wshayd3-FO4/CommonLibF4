#pragma once

#include "RE/Bethesda/PipboyArray.h"
#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class __declspec(novtable) PipboyPerksData :
		public PipboyDataGroup,                                      // 00
		public BSTEventSink<PerkValueEvents::PerkValueChangedEvent>  // 98
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPerksData };
		static constexpr auto VTABLE{ VTABLE::PipboyPerksData };

		virtual ~PipboyPerksData() = default;

		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkValueChangedEvent& a_event, BSTEventSource<PerkValueEvents::PerkValueChangedEvent>* a_source);  // 01

		// override
		virtual void Populate(bool a_arg1) override;  // 02
		virtual void DoClearData() override;          // 03
		virtual void DoClearSink() override;          // 04

		PipboyArray*             perkChains;      // A0
		BSTArray<const BGSPerk*> perkChainRoots;  // A8
		BSTArray<PipboyObject*>  perksArray;      // C0
	};
	static_assert(sizeof(PipboyPerksData) == 0xD8);
}
