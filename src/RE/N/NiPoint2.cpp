#include "RE/N/NiPoint2.h"

namespace RE
{
	const NiPoint2 NiPoint2::ZERO = { 0.0F, 0.0F };

	NiPoint2::NiPoint2(float a_x, float a_y) noexcept :
		x(a_x), y(a_y)
	{}

	float& NiPoint2::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 2);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint2::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 2);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint2::operator==(const NiPoint2& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y);
	}

	bool NiPoint2::operator!=(const NiPoint2& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint2::operator<(const NiPoint2& a_rhs) const noexcept
	{
		return std::tie(x, y) < std::tie(a_rhs.x, a_rhs.y);
	}

	bool NiPoint2::operator>(const NiPoint2& a_rhs) const noexcept
	{
		return std::tie(x, y) > std::tie(a_rhs.x, a_rhs.y);
	}

	NiPoint2 NiPoint2::operator+(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x + a_rhs.x, y + a_rhs.y);
	}

	NiPoint2 NiPoint2::operator-(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x - a_rhs.x, y - a_rhs.y);
	}

	NiPoint2 NiPoint2::operator*(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x * a_rhs.x, y * a_rhs.y);
	}

	NiPoint2 NiPoint2::operator/(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x / a_rhs.x, y / a_rhs.y);
	}

	NiPoint2 NiPoint2::operator*(float a_scalar) const noexcept
	{
		return NiPoint2(x * a_scalar, y * a_scalar);
	}

	NiPoint2 NiPoint2::operator/(float a_scalar) const noexcept
	{
		return NiPoint2(x / a_scalar, y / a_scalar);
	}

	NiPoint2 NiPoint2::operator-() const noexcept
	{
		return NiPoint2(-x, -y);
	}

	NiPoint2& NiPoint2::operator+=(const NiPoint2& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator-=(const NiPoint2& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator*=(const NiPoint2& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator/=(const NiPoint2& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		return *this;
	}
}
