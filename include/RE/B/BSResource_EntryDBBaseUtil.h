#pragma once

namespace RE::BSResource
{
	class EntryBase;
	class Location;

	class EntryDBBaseUtil
	{
	public:
		static bool ReleaseEntryAction(EntryBase* a_entry)
		{
			using func_t = decltype(&EntryDBBaseUtil::ReleaseEntryAction);
			static REL::Relocation<func_t> func{ REL::ID(777279) };
			return func(a_entry);
		}

		// members
		Location*     rootLocation;           // 00
		std::uint32_t resourcePriorityBase;   // 08
		bool          allowDeadLoadSkipping;  // 0C
	};
	static_assert(sizeof(EntryDBBaseUtil) == 0x10);
}
