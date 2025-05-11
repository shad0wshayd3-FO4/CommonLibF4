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

	template <class E, class U>
	using hkEnum = REX::Enum<E, U>;

	template <class E, class U>
	using hkFlags = REX::EnumSet<E, U>;

	class hkHalf
	{
	public:
		std::int16_t value;
	};

	template <class T>
	class hkPadSpu
	{
	public:
		~hkPadSpu() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		T storage;
	};

	using hkReal = float;

	enum class hkResultEnum
	{
		kSuccess,
		kFailure
	};

	struct hkResult
	{
	public:
		~hkResult() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		hkResultEnum e;  // 0
	};
	static_assert(sizeof(hkResult) == 0x4);
}
