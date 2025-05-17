#pragma once

namespace RE
{
	class BGSCraftItemEvent
	{
	public:
		BGSCraftItemEvent(TESObjectREFR* a_workbench, BGSLocation* a_location, TESForm* a_baseObject) :
			location(a_location), createdItemBase(a_baseObject)
		{
			if (a_workbench) {
				workbench = a_workbench->GetHandle();
			}
		}

		[[nodiscard]] static std::uint32_t EVENT_INDEX()
		{
			static REL::Relocation<std::uint32_t*> eventIdx{ ID::BGSCraftItemEvent::EventIndex };
			return *eventIdx;
		}

		// members
		ObjectRefHandle workbench;        // 00
		BGSLocation*    location;         // 08
		TESForm*        createdItemBase;  // 10
	};
	static_assert(sizeof(BGSCraftItemEvent) == 0x18);
}
