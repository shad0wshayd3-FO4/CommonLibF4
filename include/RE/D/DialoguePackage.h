#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/T/TESPackage.h"

namespace RE
{
	class __declspec(novtable) DialoguePackage :
		public TESPackage  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::DialoguePackage };
		static constexpr auto VTABLE{ VTABLE::DialoguePackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// members
		ActorHandle     talkingActor;      // C8
		ObjectRefHandle genericSecondLoc;  // CC
		ActorHandle     actor;             // D0
		ActorHandle     targetActor;       // D4
		bool            actorHeadTrack;    // D8
		bool            createdPack;       // D9
		float           eventWaitTimer;    // DC
		float           listenTimer;       // E0
		bool            sceneGenerated;    // E4
	};
	static_assert(sizeof(DialoguePackage) == 0xE8);
}
