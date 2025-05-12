#pragma once

namespace RE
{
	template <class T>
	struct BSTSmartPointerAutoPtr
	{
	public:
		constexpr static void Acquire(stl::not_null<T*> a_ptr) { return; }
		static void           Release(stl::not_null<T*> a_ptr) { delete a_ptr; }
	};
}
