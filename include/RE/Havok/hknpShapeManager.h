#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"

namespace RE
{
	class hknpShapeManager
	{
	public:
		struct MutableShapeInfo;

		// members
		hkArray<MutableShapeInfo*> mutableShapeInfos;
		hkArray<MutableShapeInfo*> freeMutableShapeInfos;
		hkBool                     isAnyShapeMutated;
	};
	static_assert(sizeof(hknpShapeManager) == 0x28);
}
