#pragma once

namespace RE
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
	public:
		static void Acquire(stl::not_null<T*> a_ptr) { a_ptr->IncRef(); }

		static void Release(stl::not_null<T*> a_ptr)
		{
			if (a_ptr->DecRef() == 0) {
				delete a_ptr;
			}
		}
	};
}
