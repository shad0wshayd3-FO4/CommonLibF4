#pragma once

namespace RE
{
	struct TESCellAttachDetachEvent
	{
		[[nodiscard]] static BSTEventSource<TESCellAttachDetachEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellAttachDetachEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201823) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> refr;
		bool                     isAttaching;
	};
	static_assert(sizeof(TESCellAttachDetachEvent) == 0x10);
}
