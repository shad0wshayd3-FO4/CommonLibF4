#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSNavmeshGrid.h"

namespace RE
{
	class BSNavmeshClosedDoorInfo;
	class BSNavmeshCoverEdge;
	class BSNavmeshEdgeExtraInfo;
	class BSNavmeshInfo;
	class BSNavmeshObstacleData;
	class BSNavmeshObstacleUndoData;
	class BSNavmeshTriangle;
	class BSNavmeshTriangleDoorPortal;
	class BSNavmeshVertex;
	class BSNavmeshWaypoint;
	class BSPathingCell;

	class __declspec(novtable) BSNavmesh :
		public BSIntrusiveRefCounted  // 008
	{
	public:
		static constexpr auto RTTI{ RTTI::BSNavmesh };
		static constexpr auto VTABLE{ VTABLE::BSNavmesh };

		struct DisabledLink
		{
		public:
			// members
			std::uint16_t triIndex;      // 0
			std::uint16_t adjTriIndex;   // 2
			std::int32_t  edgeIndex;     // 4
			std::int32_t  adjEdgeIndex;  // 8
		};
		static_assert(sizeof(DisabledLink) == 0xC);

		virtual ~BSNavmesh();  // 00

		// add
		virtual std::uint32_t QNavmeshID() const = 0;  // 01

		// members
		BSTArray<BSNavmeshVertex>                                    vertices;               // 010
		BSTArray<BSNavmeshTriangle>                                  triangles;              // 028
		BSTArray<BSNavmeshEdgeExtraInfo>                             extraEdgeInfo;          // 040
		BSTArray<BSNavmeshTriangleDoorPortal>                        doorPortals;            // 058
		BSTArray<BSNavmeshClosedDoorInfo>                            closedDoors;            // 070
		BSTArray<BSNavmeshCoverEdge>                                 coverArray;             // 088
		BSTHashMap<std::uint16_t, std::uint16_t>                     coverMap;               // 0A0
		BSNavmeshGrid                                                meshGrid;               // 0D0
		BSTArray<NiPointer<BSNavmeshObstacleUndoData>>               obstacles;              // 100
		BSTHashMap<std::uint16_t, NiPointer<BSNavmeshObstacleData>>* triangleToObstacleMap;  // 118
		BSTArray<std::uint16_t>                                      obstaclePOVs;           // 120
		BSTHashMap<std::uint32_t, BSTArray<std::uint16_t>*>          precuts;                // 138
		BSTSet<std::uint32_t>                                        activePrecuts;          // 168
		BSTHashMap<std::uint32_t, std::uint32_t>                     portalSwaps;            // 198
		BSTArray<BSNavmesh::DisabledLink>                            disabledLinks;          // 1C8
		BSTSmartPointer<BSPathingCell>                               parentCell;             // 1E0
		BSNavmeshInfo*                                               navmeshInfo;            // 1E8
		BSTArray<BSNavmeshWaypoint>                                  waypoints;              // 1F0
	};
	static_assert(sizeof(BSNavmesh) == 0x208);
}
