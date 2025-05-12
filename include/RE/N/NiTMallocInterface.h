#pragma once

namespace RE
{
	template <class T>
	class NiTMallocInterface
	{
	public:
		[[nodiscard]] static T* allocate(std::size_t a_num) { return NiMalloc(sizeof(T) * a_num); }
		static void             deallocate(T* a_ptr) { NiFree(a_ptr); }
	};
}
