#pragma once

namespace RE
{
	class NiPoint3
	{
	public:
		static const NiPoint3 ZERO;

		NiPoint3() noexcept = default;
		NiPoint3(const NiPoint2& a_point) noexcept;
		NiPoint3(float a_x, float a_y, float a_z) noexcept;

		float&       operator[](std::size_t a_pos) noexcept;
		const float& operator[](std::size_t a_pos) const noexcept;
		bool         operator==(const NiPoint3& a_rhs) const noexcept;
		bool         operator!=(const NiPoint3& a_rhs) const noexcept;
		bool         operator<(const NiPoint3& a_rhs) const noexcept;
		bool         operator>(const NiPoint3& a_rhs) const noexcept;
		NiPoint3     operator+(const NiPoint3& a_rhs) const noexcept;
		NiPoint3     operator-(const NiPoint3& a_rhs) const noexcept;
		NiPoint3     operator*(const NiPoint3& a_rhs) const noexcept;
		NiPoint3     operator/(const NiPoint3& a_rhs) const noexcept;
		NiPoint3     operator*(float a_scalar) const noexcept;
		NiPoint3     operator/(float a_scalar) const noexcept;
		NiPoint3     operator-() const noexcept;
		NiPoint3&    operator+=(const NiPoint3& a_rhs) noexcept;
		NiPoint3&    operator-=(const NiPoint3& a_rhs) noexcept;
		NiPoint3&    operator*=(const NiPoint3& a_rhs) noexcept;
		NiPoint3&    operator/=(const NiPoint3& a_rhs) noexcept;
		NiPoint3&    operator+=(float a_scalar) noexcept;
		NiPoint3&    operator-=(float a_scalar) noexcept;
		NiPoint3&    operator*=(float a_scalar) noexcept;
		NiPoint3&    operator/=(float a_scalar) noexcept;

		[[nodiscard]] NiPoint3 Cross(const NiPoint3& a_point) const noexcept;
		[[nodiscard]] float    Dot(const NiPoint3& a_point) const noexcept;
		[[nodiscard]] float    GetDistance(const NiPoint3& a_point) const noexcept;
		[[nodiscard]] float    GetSquaredDistance(const NiPoint3& a_point) const noexcept;
		[[nodiscard]] float    GetZAngleFromVector() const;
		[[nodiscard]] float    Length() const noexcept;
		[[nodiscard]] float    SqrLength() const noexcept;
		[[nodiscard]] NiPoint3 UnitCross(const NiPoint3& a_point) const noexcept;
		float                  Unitize() noexcept;

		// members
		float x{ 0.0F };  // 00
		float y{ 0.0F };  // 04
		float z{ 0.0F };  // 08
	};
	static_assert(sizeof(NiPoint3) == 0xC);
}

template <>
struct std::formatter<RE::NiPoint3>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiPoint3& a_point, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "({}, {}, {})", a_point.x, a_point.y, a_point.z);
	}
};
