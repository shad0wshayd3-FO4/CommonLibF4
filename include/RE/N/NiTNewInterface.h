#pragma once

namespace RE
{
	template <class T>
	class NiTNewInterface
	{
	public:
		[[nodiscard]] static T* allocate(std::size_t a_num) { return new T[a_num]; }
		static void             deallocate(T* a_ptr) { delete[] a_ptr; }
	};
}
