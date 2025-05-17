#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace AnimationSystemUtils
	{
		inline bool WillEventChangeState(const TESObjectREFR& a_ref, const BSFixedString& a_evn)
		{
			using func_t = decltype(&WillEventChangeState);
			static REL::Relocation<func_t> func{ REL::ID(35074) };
			return func(a_ref, a_evn);
		}
	}
}
