#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESPackage.h"
#include "RE/N/NiPoint.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class __declspec(novtable) FleePackage :
		public TESPackage  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::FleePackage };
		static constexpr auto VTABLE{ VTABLE::FleePackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// members
		BSTArray<ObjectRefHandle> avoidRefs;      // 0C8
		NiPoint3                  fleePoint;      // 0E0
		float                     fleeTimer;      // 0EC
		ObjectRefHandle           teleportDoor;   // 0F0
		ObjectRefHandle           refFleeTo;      // 0F4
		bool                      evaluatePoint;  // 0F8
		bool                      combatMode;     // 0F9
		bool                      fleeSucceeded;  // 0FA
		bool                      knowstarget;    // 0FB
		bool                      usehorse;       // 0FC
	};
	static_assert(sizeof(FleePackage) == 0x100);
}
