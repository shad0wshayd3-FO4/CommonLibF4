#pragma once

namespace RE
{
	class NiPoint4
	{
	public:
		static const NiPoint4 ZERO;
		static const NiPoint4 IDENTITY0;
		static const NiPoint4 IDENTITY1;
		static const NiPoint4 IDENTITY2;
		static const NiPoint4 IDENTITY3;

		NiPoint4() noexcept = default;
		NiPoint4(const NiPoint2& a_point) noexcept;
		NiPoint4(const NiPoint3& a_point) noexcept;
		NiPoint4(float a_x, float a_y, float a_z, float a_w) noexcept;

		float&       operator[](std::size_t a_pos) noexcept;
		const float& operator[](std::size_t a_pos) const noexcept;
		bool         operator==(const NiPoint4& a_rhs) const noexcept;
		bool         operator!=(const NiPoint4& a_rhs) const noexcept;
		bool         operator<(const NiPoint4& a_rhs) const noexcept;
		bool         operator>(const NiPoint4& a_rhs) const noexcept;
		NiPoint4     operator+(const NiPoint4& a_rhs) const noexcept;
		NiPoint4     operator-(const NiPoint4& a_rhs) const noexcept;
		NiPoint4     operator*(const NiPoint4& a_rhs) const noexcept;
		NiPoint4     operator/(const NiPoint4& a_rhs) const noexcept;
		NiPoint4     operator*(float a_scalar) const noexcept;
		NiPoint4     operator/(float a_scalar) const noexcept;
		NiPoint4     operator-() const noexcept;
		NiPoint4&    operator+=(const NiPoint4& a_rhs) noexcept;
		NiPoint4&    operator-=(const NiPoint4& a_rhs) noexcept;
		NiPoint4&    operator*=(const NiPoint4& a_rhs) noexcept;
		NiPoint4&    operator/=(const NiPoint4& a_rhs) noexcept;
		NiPoint4&    operator+=(float a_scalar) noexcept;
		NiPoint4&    operator-=(float a_scalar) noexcept;
		NiPoint4&    operator*=(float a_scalar) noexcept;
		NiPoint4&    operator/=(float a_scalar) noexcept;

		// members
		float x{ 0.0F };  // 00
		float y{ 0.0F };  // 04
		float z{ 0.0F };  // 08
		float w{ 0.0F };  // 0C
	};
	static_assert(sizeof(NiPoint4) == 0x10);
}

template <>
struct std::formatter<RE::NiPoint4>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiPoint4& a_point, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "({}, {}, {}, {})", a_point.x, a_point.y, a_point.z, a_point.w);
	}
};
