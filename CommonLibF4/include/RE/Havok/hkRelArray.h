#pragma once

namespace RE
{
	template <class T>
	class hkRelArray
	{
	public:
		hkRelArray() {};

		T& operator[](const std::int32_t a_index)
		{
			assert(a_index >= 0);
			assert(a_index < m_size);
			return reinterpret_cast<T*>(reinterpret_cast<char*>(this) + m_offset)[a_index];
		}

		const T& operator[](const std::int32_t a_index) const
		{
			assert(a_index >= 0);
			assert(a_index < m_size);
			return reinterpret_cast<const T*>(reinterpret_cast<const char*>(this) + m_offset)[a_index];
		}

		T* begin()
		{
			return reinterpret_cast<T*>(reinterpret_cast<char*>(this) + m_offset);
		}

		const T* begin() const
		{
			return reinterpret_cast<const T*>(reinterpret_cast<const char*>(this) + m_offset);
		}

	protected:
		std::uint16_t m_size;
		std::uint16_t m_offset;
	};
	static_assert(sizeof(hkRelArray<std::byte>) == 0x4);
}
