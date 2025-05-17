#pragma once

#include "RE/B/BSSimpleList.h"

namespace RE
{
	class PackageList
	{
	public:
		// members
		BSSimpleList<TESPackage*> listPackages;
	};
	static_assert(sizeof(PackageList) == 0x10);
}
