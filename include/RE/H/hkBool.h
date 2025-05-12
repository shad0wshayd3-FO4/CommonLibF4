#pragma once

namespace RE
{
	class hkBool
	{
	public:
		hkBool(){};  // empty constructor

		hkBool(bool a_bool)
		{
			m_bool = static_cast<char>(a_bool);
		}

		~hkBool() noexcept {}  // intentional

		operator bool() const
		{
			return m_bool != 0;
		}

	private:
		char m_bool;
	};
	static_assert(sizeof(hkBool) == 0x1);

	using hkBool32 = std::uint32_t;
}
