#pragma once

namespace RE
{
	class hkStringPtr
	{
	public:
		using size_type = std::int32_t;

		hkStringPtr() = default;

		hkStringPtr(const char* a_data)
		{
			using func_t = std::add_pointer_t<void(hkStringPtr*, const char*)>;
			static REL::Relocation<func_t> func{ REL::ID(2255573) };
			func(this, a_data);
		}

		const char* data() const noexcept
		{
			return reinterpret_cast<const char*>(reinterpret_cast<std::uintptr_t>(m_data) & ~kManaged);
		}

		const char* c_str() const noexcept
		{
			return data();
		}

		bool empty() const noexcept
		{
			return !m_data || m_data[0] == '\0';
		}

		size_type size() const
		{
			return static_cast<size_type>(std::strlen(data()));
		}

		size_type length() const
		{
			return size();
		}

	protected:
		enum : std::int32_t
		{
			kManaged = 1 << 0
		};

		const char* m_data{ nullptr };  // 0
	};
	static_assert(sizeof(hkStringPtr) == 0x8);
}
