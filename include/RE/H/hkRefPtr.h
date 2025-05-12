#pragma once

namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		hkRefPtr() = default;

		hkRefPtr(std::nullptr_t) noexcept {};

		hkRefPtr(T* a_ptr) :
			m_ptr(a_ptr)
		{
			TryAddReference();
		}

		hkRefPtr(const hkRefPtr& a_other) :
			m_ptr(a_other.m_ptr)
		{
			TryAddReference();
		}

		~hkRefPtr() noexcept
		{
			TryRemoveReference();
		}

		hkRefPtr& operator=(T* a_ptr)
		{
			if (m_ptr != a_ptr) {
				TryRemoveReference();
				m_ptr = a_ptr;
				TryAddReference();
			}

			return *this;
		}

	public:
		T* get() const noexcept { return m_ptr; }

	public:
		T& operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return *m_ptr;
		}

		T* operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return m_ptr;
		}

		explicit operator bool() const noexcept
		{
			return m_ptr != nullptr;
		}

	private:
		void TryAddReference()
		{
			if (m_ptr)
				reinterpret_cast<hkReferencedObject*>(m_ptr)->AddReference();
		}

		void TryRemoveReference()
		{
			if (m_ptr) {
				reinterpret_cast<hkReferencedObject*>(m_ptr)->RemoveReference();
				m_ptr = nullptr;
			}
		}

	private:
		T* m_ptr{ nullptr };
	};
}
