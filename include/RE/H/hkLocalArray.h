#pragma once

namespace RE
{
	template <class T>
	class hkLocalArray :
		public hkArray<T>
	{
	public:
		hkLocalArray(std::int32_t a_capacity) :
			m_initialCapacity(a_capacity)
		{
			this->m_capacityAndFlags = a_capacity | hkArray<T>::kDontDeallocateFlag;
			m_localMemory = this->data;
		}

		~hkLocalArray()
		{
			if (!WasReallocated())
				hkArray<T>::clear();

			hkDeallocateStack<T>(m_localMemory, m_initialCapacity);
		}

		hkBool WasReallocated() const
		{
			return m_localMemory != this->m_data;
		}

		T*           m_localMemory;
		std::int32_t m_initialCapacity;
	};
}
