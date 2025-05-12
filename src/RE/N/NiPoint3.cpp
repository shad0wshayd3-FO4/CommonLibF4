#include "RE/N/NiPoint3.h"

namespace RE
{
	const NiPoint3  NiPoint3::ZERO = { 0.0F, 0.0F, 0.0F };
	const NiPoint3A NiPoint3A::ZERO = { 0.0F, 0.0F, 0.0F };

	NiPoint3::NiPoint3(const NiPoint2& a_point) noexcept :
		x(a_point.x), y(a_point.y)
	{}

	NiPoint3::NiPoint3(float a_x, float a_y, float a_z) noexcept :
		x(a_x), y(a_y), z(a_z)
	{}

	float& NiPoint3::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 3);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint3::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 3);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint3::operator==(const NiPoint3& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z);
	}

	bool NiPoint3::operator!=(const NiPoint3& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint3::operator<(const NiPoint3& a_rhs) const noexcept
	{
		return std::tie(x, y, z) < std::tie(a_rhs.x, a_rhs.y, a_rhs.z);
	}

	bool NiPoint3::operator>(const NiPoint3& a_rhs) const noexcept
	{
		return std::tie(x, y, z) > std::tie(a_rhs.x, a_rhs.y, a_rhs.z);
	}

	NiPoint3 NiPoint3::operator+(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}

	NiPoint3 NiPoint3::operator-(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}

	NiPoint3 NiPoint3::operator*(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
	}

	NiPoint3 NiPoint3::operator/(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
	}

	NiPoint3 NiPoint3::operator*(float a_scalar) const noexcept
	{
		return NiPoint3(x * a_scalar, y * a_scalar, z * a_scalar);
	}

	NiPoint3 NiPoint3::operator/(float a_scalar) const noexcept
	{
		return NiPoint3(x / a_scalar, y / a_scalar, z / a_scalar);
	}

	NiPoint3 NiPoint3::operator-() const noexcept
	{
		return NiPoint3(-x, -y, -z);
	}

	NiPoint3& NiPoint3::operator+=(const NiPoint3& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator-=(const NiPoint3& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator*=(const NiPoint3& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		z *= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator/=(const NiPoint3& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		z /= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		z += a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		z -= a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		z /= a_scalar;
		return *this;
	}

	NiPoint3 NiPoint3::Cross(const NiPoint3& a_point) const noexcept
	{
		return NiPoint3(
			y * a_point.z - z * a_point.y,
			z * a_point.x - x * a_point.z,
			x * a_point.y - y * a_point.x);
	}

	float NiPoint3::Dot(const NiPoint3& a_point) const noexcept
	{
		return x * a_point.x + y * a_point.y + z * a_point.z;
	}

	float NiPoint3::GetDistance(const NiPoint3& a_point) const noexcept
	{
		return std::sqrtf(GetSquaredDistance(a_point));
	}

	float NiPoint3::GetSquaredDistance(const NiPoint3& a_point) const noexcept
	{
		const float dx = a_point.x - x;
		const float dy = a_point.y - y;
		const float dz = a_point.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	float NiPoint3::GetZAngleFromVector() const
	{
		using func_t = decltype(&NiPoint3::GetZAngleFromVector);
		static REL::Relocation<func_t> func{ REL::ID(1450064) };
		return func(this);
	}

	float NiPoint3::Length() const noexcept
	{
		return std::sqrtf(x * x + y * y + z * z);
	}

	float NiPoint3::SqrLength() const noexcept
	{
		return x * x + y * y + z * z;
	}

	NiPoint3 NiPoint3::UnitCross(const NiPoint3& a_point) const noexcept
	{
		auto cross = Cross(a_point);
		cross.Unitize();
		return cross;
	}

	float NiPoint3::Unitize() noexcept
	{
		auto length = Length();
		if (length == 1.f) {
			return length;
		} else if (length > FLT_EPSILON) {
			operator/=(length);
		} else {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			length = 0.0;
		}
		return length;
	}
}
