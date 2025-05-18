#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBool.h"
#include "RE/H/hknpBodyId.h"
#include "RE/H/hkFlags.h"
#include "RE/H/hknpShapeSignals.h"

namespace RE
{
	class hknpShape;

	class hknpShapeManager
	{
	public:
		class MutableShapeInfo
		{
		public:
			// members
			hknpShapeManager*                                          shapeManager;  // 00
			const hknpShape*                                           shape;         // 08
			hkArray<hknpBodyId>                                        bodyIds;       // 10
			hkFlags<hknpShapeSignals::MutationFlagsEnum, std::uint8_t> mutations;     // 20
		};
		static_assert(sizeof(MutableShapeInfo) == 0x28);

		// members
		hkArray<MutableShapeInfo*> mutableShapeInfos;      // 00
		hkArray<MutableShapeInfo*> freeMutableShapeInfos;  // 10
		hkBool                     isAnyShapeMutated;      // 20
	};
	static_assert(sizeof(hknpShapeManager) == 0x28);
}
