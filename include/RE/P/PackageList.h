#pragma once

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
