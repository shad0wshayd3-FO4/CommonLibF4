#pragma once

namespace RE
{
	struct BucketTable
	{
	public:
		struct alignas(0x10) AlignedLock
		{
		public:
			// members
			volatile std::uint32_t val;  // 00
		};
		static_assert(sizeof(AlignedLock) == 0x10);

		static BucketTable& GetSingleton()
		{
			using func_t = decltype(&BucketTable::GetSingleton);
			static REL::Relocation<func_t> func{ REL::ID(2268736) };
			return func();
		}

		// members
		BSStringPool::Entry* buckets[0x10000];        // 00000
		AlignedLock          locks[0x10000 / 0x200];  // 80000
		bool                 initialized;             // 80800
	};
	static_assert(sizeof(BucketTable) == 0x80810);
}
