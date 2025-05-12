#pragma once

namespace RE
{
	struct BGSPickLockEvent
	{
	public:
		BGSPickLockEvent(TESObjectREFR* a_actor, TESObjectREFR* a_lockRef, bool a_isCrime)
		{
			ctor(a_actor, a_lockRef, a_isCrime);
		}

		[[nodiscard]] static std::uint32_t EVENT_INDEX()
		{
			static REL::Relocation<std::uint32_t*> eventIdx{ REL::ID(701969) };
			return *eventIdx;
		}

		// members
		ObjectRefHandle actor;       // 00
		ObjectRefHandle lockObject;  // 04
		std::uint32_t   isCrime;     // 08

	private:
		BGSPickLockEvent* ctor(TESObjectREFR* a_actor, TESObjectREFR* a_lockRef, bool a_isCrime)
		{
			using func_t = decltype(&BGSPickLockEvent::ctor);
			static REL::Relocation<func_t> func{ REL::ID(193329) };
			return func(this, a_actor, a_lockRef, a_isCrime);
		}
	};
	static_assert(sizeof(BGSPickLockEvent) == 0x0C);
}
