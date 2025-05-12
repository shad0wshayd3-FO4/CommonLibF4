#pragma once

namespace RE
{
	template <class T>
	struct BSTSmartPointerGamebryoRefCount
	{
	public:
		constexpr static void Acquire(stl::not_null<T*> a_ptr) { a_ptr->IncRefCount(); }
		static void           Release(stl::not_null<T*> a_ptr) { a_ptr->DecRefCount(); }
	};
}
