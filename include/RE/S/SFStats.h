#pragma once

namespace RE::Scaleform
{
	enum StatBasicValues : std::int32_t
	{
		kStatGroup_Default = 0,
		kStatGroup_Core = 16,

		kStat_Mem = kStatGroup_Default + 1,
		kStat_Default_Mem = kStat_Mem + 1,

		kStatHeap_Start = kStatGroup_Core,

		kStat_MaxId = 64 << 6,
		kStat_EntryCount = 512,

		kHeapId_Default = 1
	};

	class StatBag
	{
	public:
	};
	static_assert(std::is_empty_v<StatBag>);
}
