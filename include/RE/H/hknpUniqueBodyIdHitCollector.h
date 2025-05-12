#pragma once

namespace RE
{
	class __declspec(novtable) hknpUniqueBodyIdHitCollector :
		public hknpAllHitsCollector  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpUniqueBodyIdHitCollector };
		static constexpr auto VTABLE{ VTABLE::hknpUniqueBodyIdHitCollector };

		// members
		hkRefPtr<hknpBSWorld> latentWorld;  // 3F0
	};
	static_assert(sizeof(hknpUniqueBodyIdHitCollector) == 0x400);
}
