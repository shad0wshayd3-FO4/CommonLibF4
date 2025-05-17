#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class NavMesh;

	class BGSNavmeshableObject
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSNavmeshableObject };

		// members
		BSTSmartPointer<NavMesh> embeddedNavmesh;  // 0
	};
	static_assert(sizeof(BGSNavmeshableObject) == 0x8);
}
