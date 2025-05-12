#pragma once

namespace RE
{
	class NiPoint2
	{
	public:
		static const NiPoint2 ZERO;

		NiPoint2() noexcept = default;
		NiPoint2(float a_x, float a_y) noexcept;

		float&       operator[](std::size_t a_pos) noexcept;
		const float& operator[](std::size_t a_pos) const noexcept;
		bool         operator==(const NiPoint2& a_rhs) const noexcept;
		bool         operator!=(const NiPoint2& a_rhs) const noexcept;
		bool         operator<(const NiPoint2& a_rhs) const noexcept;
		bool         operator>(const NiPoint2& a_rhs) const noexcept;
		NiPoint2     operator+(const NiPoint2& a_rhs) const noexcept;
		NiPoint2     operator-(const NiPoint2& a_rhs) const noexcept;
		NiPoint2     operator*(const NiPoint2& a_rhs) const noexcept;
		NiPoint2     operator/(const NiPoint2& a_rhs) const noexcept;
		NiPoint2     operator*(float a_scalar) const noexcept;
		NiPoint2     operator/(float a_scalar) const noexcept;
		NiPoint2     operator-() const noexcept;
		NiPoint2&    operator+=(const NiPoint2& a_rhs) noexcept;
		NiPoint2&    operator-=(const NiPoint2& a_rhs) noexcept;
		NiPoint2&    operator*=(const NiPoint2& a_rhs) noexcept;
		NiPoint2&    operator/=(const NiPoint2& a_rhs) noexcept;
		NiPoint2&    operator+=(float a_scalar) noexcept;
		NiPoint2&    operator-=(float a_scalar) noexcept;
		NiPoint2&    operator*=(float a_scalar) noexcept;
		NiPoint2&    operator/=(float a_scalar) noexcept;

		// members
		float x{ 0.0F };  // 00
		float y{ 0.0F };  // 04
	};
	static_assert(sizeof(NiPoint2) == 0x8);
}

template <>
struct std::formatter<RE::NiPoint2>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiPoint2& a_point, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "({}, {})", a_point.x, a_point.y);
	}
};
