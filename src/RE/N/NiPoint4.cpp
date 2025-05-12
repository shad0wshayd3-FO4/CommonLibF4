#include "RE/N/NiPoint4.h"

namespace RE
{
	const NiPoint4 NiPoint4::ZERO = { 0.0F, 0.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY0 = { 1.0F, 0.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY1 = { 0.0F, 1.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY2 = { 0.0F, 0.0F, 1.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY3 = { 0.0F, 0.0F, 0.0F, 1.0F };

	NiPoint4::NiPoint4(const NiPoint2& a_point) noexcept :
		x(a_point.x), y(a_point.y)
	{}

	NiPoint4::NiPoint4(const NiPoint3& a_point) noexcept :
		x(a_point.x), y(a_point.y), z(a_point.z)
	{}

	NiPoint4::NiPoint4(float a_x, float a_y, float a_z, float a_w) noexcept :
		x(a_x), y(a_y), z(a_z), w(a_w)
	{}

	float& NiPoint4::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 4);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint4::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 4);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint4::operator==(const NiPoint4& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z) && (w == a_rhs.w);
	}

	bool NiPoint4::operator!=(const NiPoint4& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint4::operator<(const NiPoint4& a_rhs) const noexcept
	{
		return std::tie(x, y, z, w) < std::tie(a_rhs.x, a_rhs.y, a_rhs.z, a_rhs.w);
	}

	bool NiPoint4::operator>(const NiPoint4& a_rhs) const noexcept
	{
		return std::tie(x, y, z, w) > std::tie(a_rhs.x, a_rhs.y, a_rhs.z, a_rhs.w);
	}

	NiPoint4 NiPoint4::operator+(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
	}

	NiPoint4 NiPoint4::operator-(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
	}

	NiPoint4 NiPoint4::operator*(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
	}

	NiPoint4 NiPoint4::operator/(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z, w / a_rhs.w);
	}

	NiPoint4 NiPoint4::operator*(float a_scalar) const noexcept
	{
		return NiPoint4(x * a_scalar, y * a_scalar, z * a_scalar, w * a_scalar);
	}

	NiPoint4 NiPoint4::operator/(float a_scalar) const noexcept
	{
		return operator*(1.0F / a_scalar);
	}

	NiPoint4 NiPoint4::operator-() const noexcept
	{
		return NiPoint4(-x, -y, -z, -w);
	}

	NiPoint4& NiPoint4::operator+=(const NiPoint4& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		w += a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator-=(const NiPoint4& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		w -= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator*=(const NiPoint4& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		z *= a_rhs.z;
		w *= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator/=(const NiPoint4& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		z /= a_rhs.z;
		w /= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		z += a_scalar;
		w += a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		z -= a_scalar;
		w -= a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		w *= a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		z /= a_scalar;
		w /= a_scalar;
		return *this;
	}
}
