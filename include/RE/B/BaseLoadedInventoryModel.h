#pragma once

#include "RE/B/BGSCreatedObjectManager.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiAVObject;

	class BaseLoadedInventoryModel
	{
	public:
		// members
		CreatedObjPtr<TESForm> itemBase;             // 00
		TESBoundObject*        modelObj;             // 08
		NiPointer<NiAVObject>  model;                // 10
		NiPoint2               panMinima;            // 18
		NiPoint2               panMaxima;            // 20
		float                  initialDistance;      // 28
		float                  boundRadius;          // 2C
		float                  horizontalBound;      // 30
		float                  verticalBound;        // 34
		float                  verticalBoundOffset;  // 38
	};
	static_assert(sizeof(BaseLoadedInventoryModel) == 0x40);
}
