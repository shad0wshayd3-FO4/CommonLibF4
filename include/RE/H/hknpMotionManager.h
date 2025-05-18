#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBool.h"
#include "RE/H/hknpMotionId.h"

namespace RE
{
	class hknpBodyManager;
	class hknpMotion;

	class hknpMotionManager
	{
	public:
		class CellData
		{
		public:
			// members
			hkArray<hknpMotionId> solverIdToMotionId;  // 10
		};
		static_assert(sizeof(CellData) == 0x10);

		// members
		hknpBodyManager*    m_bodyManager;              // 00
		hkArray<hknpMotion> m_motions;                  // 08
		hkBool              m_motionBufferIsUserOwned;  // 18
		hknpMotionId        m_firstFreeMotionId;        // 1C
		hknpMotionId        m_firstMarkedMotionId;      // 20
		std::uint32_t       m_numAllocatedMotions;      // 24
		std::uint32_t       m_numMarkedMotions;         // 28
		std::uint32_t       m_peakMotionIndex;          // 2C
		hkArray<CellData>   m_activeMotionGrid;         // 30
		hkBool              m_isLocked;                 // 40
	};
	static_assert(sizeof(hknpMotionManager) == 0x48);
}
