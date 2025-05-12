#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class DoorTeleportData;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESWorldSpace;

	struct PLAYER_TARGET_LOC
	{
	public:
		using ArrivalFunc_t = void(void*);

		// members
		TESWorldSpace*    world;             // 00
		TESObjectCELL*    interior;          // 08
		DoorTeleportData* transitionTel;     // 10
		NiPoint3          location;          // 18
		NiPoint3          angle;             // 24
		TESObjectREFR*    walkThroughDoor;   // 30
		ArrivalFunc_t*    arrivalFunc;       // 38
		void*             arrivalFuncData;   // 40
		ObjectRefHandle   furnitureRef;      // 48
		ObjectRefHandle   fastTravelMarker;  // 4C
		float             fastTravelDist;    // 50
		bool              resetWeather;      // 54
		bool              allowAutoSave;     // 55
		bool              preventLoadMenu;   // 56
		bool              skyTransition;     // 57
		bool              isValid;           // 58
	};
	static_assert(sizeof(PLAYER_TARGET_LOC) == 0x60);
}
