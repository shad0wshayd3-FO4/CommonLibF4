#pragma once

#include "RE/B/BSTObjectArena.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	class IAnimationGraphManagerHolder;

	namespace BGSAnimationSystemUtils
	{
		class ActiveSyncInfo
		{
		public:
			// members
			BSTObjectArena<BSTTuple<BSFixedString, float>> otherSyncInfo;    // 00
			float                                          currentAnimTime;  // 40
			float                                          animSpeedMult;    // 44
			float                                          totalAnimTime;    // 48
		};
		static_assert(sizeof(ActiveSyncInfo) == 0x50);

		inline bool GetActiveSyncInfo(const IAnimationGraphManagerHolder* a_graphHolder, ActiveSyncInfo& a_infoOut)
		{
			using func_t = decltype(&GetActiveSyncInfo);
			static REL::Relocation<func_t> func{ REL::ID(1349978) };
			return func(a_graphHolder, a_infoOut);
		}

		inline bool InitializeActorInstant(Actor& a_actor, bool a_update3D)
		{
			using func_t = decltype(&InitializeActorInstant);
			static REL::Relocation<func_t> func{ REL::ID(672857) };
			return func(a_actor, a_update3D);
		}

		inline bool IsActiveGraphInTransition(const TESObjectREFR* a_refr)
		{
			using func_t = decltype(&IsActiveGraphInTransition);
			static REL::Relocation<func_t> func{ REL::ID(839650) };
			return func(a_refr);
		}
	}
}
