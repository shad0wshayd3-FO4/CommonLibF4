#pragma once

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
