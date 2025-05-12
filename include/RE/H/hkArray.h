#pragma once

namespace RE
{
	template <class T>
	class hkArrayBase
	{
	public:
		using reference = T&;
		using const_reference = const T&;
		using iterator = T*;
		using const_iterator = const T*;

		hkArrayBase() = default;

		hkArrayBase(T* a_ptr, std::int32_t a_size, std::int32_t a_capacity) :
			m_data(a_ptr), m_size(a_size), m_capacityAndFlags(a_capacity | kDontDeallocateFlag)
		{}

		reference operator[](std::int32_t a_pos)
		{
			assert(a_pos >= 0 && a_pos < size());
			return data()[a_pos];
		}

		const_reference operator[](std::int32_t a_pos) const
		{
			assert(a_pos >= 0 && a_pos < size());
			return data()[a_pos];
		}

		T* data()
		{
			return m_data;
		}

		const T* data() const
		{
			return m_data;
		}

		reference front()
		{
			return operator[](0);
		}

		const_reference front() const
		{
			return operator[](0);
		}

		reference back()
		{
			return operator[](size() - 1);
		}

		const_reference back() const
		{
			return operator[](size() - 1);
		}

		iterator begin()
		{
			return empty() ? iterator{} : std::addressof(data()[0]);
		}

		const_iterator begin() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[0]);
		}

		const_iterator cbegin() const
		{
			return begin();
		}

		iterator end()
		{
			return empty() ? iterator{} : std::addressof(data()[size()]);
		}

		const_iterator end() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[size()]);
		}

		const_iterator cend() const
		{
			return end();
		}

		bool empty() const
		{
			return size() == 0;
		}

		std::int32_t size() const noexcept
		{
			return m_size;
		}

		std::int32_t capacity() const noexcept
		{
			return m_capacityAndFlags & kCapacityMask;
		}

		void push_back(const T& a_value)
		{
			if (size() == capacity())
				reserve(size() == 0 ? 1 : static_cast<std::int32_t>(std::ceil(size() * GROWTH_FACTOR)));

			m_data[m_size++] = a_value;
		}

		void reserve(const std::int32_t a_newCap)
		{
			assert(a_newCap <= kCapacityMask);
			if (a_newCap <= capacity()) {
				return;
			}

			auto         allocator = hkContainerHeapAllocator::GetSingleton();
			std::int32_t newSize = a_newCap * sizeof(T);
			T*           newMem = static_cast<T*>(allocator->BufAlloc(newSize));
			std::memset(newMem, 0, newSize);
			if (m_data) {
				std::int32_t oldSize = size() * sizeof(T);
				std::memcpy(newMem, m_data, oldSize);
				if ((m_capacityAndFlags & kDontDeallocateFlag) == 0) {
					allocator->BufFree(m_data, oldSize);
				}
			}

			m_data = newMem;
			m_capacityAndFlags &= ~kCapacityMask;
			m_capacityAndFlags |= a_newCap & kCapacityMask;
		}

	protected:
		enum : std::int32_t
		{
			kCapacityMask = std::int32_t(0x3FFFFFFF),
			kFlagMask = std::int32_t(0xC0000000),
			kDontDeallocateFlag = std::int32_t(0x80000000),
			kForceSigned = std::int32_t(0xFFFFFFFF)
		};

		inline static constexpr float GROWTH_FACTOR = 1.5;  // NOT PART OF NATIVE TYPE

		T*           m_data{ nullptr };                          // 00
		std::int32_t m_size{ 0 };                                // 08
		std::int32_t m_capacityAndFlags{ kDontDeallocateFlag };  // 0C
	};

	template <class T, class Allocator = hkContainerHeapAllocator>
	class hkArray :
		public hkArrayBase<T>  // 00
	{
	public:
	};

	template <class T, std::uint32_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArray :
		public hkArray<T, Allocator>  // 00
	{
	public:
	private:
		T m_storage[N];  // 10
	};

	template <class T, std::uint32_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArrayAligned16 :
		public hkArray<T, Allocator>
	{
	public:
	private:
		std::int32_t m_padding;                            // 10
		alignas(0x10) std::byte m_storage[sizeof(T) * N];  // 20
	};
	static_assert(sizeof(hkInplaceArrayAligned16<std::uint64_t, 24>) == 0xE0);

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
