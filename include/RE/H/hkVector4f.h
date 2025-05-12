#pragma once

namespace RE
{
	class __declspec(align(16)) hkVector4f
	{
	public:
		hkVector4f() = default;

		hkVector4f(const NiPoint3& a_point)
		{
			x = a_point.x;
			y = a_point.y;
			z = a_point.z;
			w = 0.0f;
		}

		hkVector4f(float a_x, float a_y, float a_z, float a_w = 0.0f)
		{
			x = a_x;
			y = a_y;
			z = a_z;
			w = a_w;
		}

		hkVector4f& operator=(const hkVector4f& a_rhs)
		{
			this->x = a_rhs.x;
			this->y = a_rhs.y;
			this->z = a_rhs.z;
			this->w = a_rhs.w;
			return *this;
		}

		hkVector4f operator+(const hkVector4f& a_rhs)
		{
			return hkVector4f(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
		}

		hkVector4f& operator+=(const hkVector4f& a_rhs)
		{
			this->x += a_rhs.x;
			this->y += a_rhs.y;
			this->z += a_rhs.z;
			this->w += a_rhs.w;
			return *this;
		}

		hkVector4f operator-(const hkVector4f& a_rhs)
		{
			return hkVector4f(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
		}

		hkVector4f operator-()
		{
			return hkVector4f(x * -1.0f, y * -1.0f, z * -1.0f);
		}

		hkVector4f& operator-=(const hkVector4f& a_rhs)
		{
			this->x -= a_rhs.x;
			this->y -= a_rhs.y;
			this->z -= a_rhs.z;
			this->w -= a_rhs.w;
			return *this;
		}

		hkVector4f operator*(float a)
		{
			return hkVector4f(x * a, y * a, z * a, w * a);
		}

		hkVector4f& operator*=(float a)
		{
			this->x *= a;
			this->y *= a;
			this->z *= a;
			this->w *= a;
			return *this;
		}

		hkVector4f operator*(const hkVector4f& a_rhs)
		{
			return hkVector4f(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
		}

		hkVector4f& operator*=(const hkVector4f& a_rhs)
		{
			this->x *= a_rhs.x;
			this->y *= a_rhs.y;
			this->z *= a_rhs.z;
			this->w *= a_rhs.w;
			return *this;
		}

		hkVector4f operator/(float a)
		{
			return hkVector4f(x / a, y / a, z / a);
		}

		hkVector4f& operator/=(float a)
		{
			this->x /= a;
			this->y /= a;
			this->z /= a;
			this->w /= a;
			return *this;
		}

		hkVector4f operator/(const hkVector4f& a_rhs)
		{
			return hkVector4f(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z, w / a_rhs.w);
		}

		hkVector4f& operator/=(const hkVector4f& a_rhs)
		{
			this->x /= a_rhs.x;
			this->y /= a_rhs.y;
			this->z /= a_rhs.z;
			this->w /= a_rhs.w;
			return *this;
		}

		float Length()
		{
			return sqrt(x * x + y * y + z * z);
		}

		hkVector4f& Normalize()
		{
			float l = Length();
			if (l == 0) {
				this->x = 0;
				this->y = 0;
				this->z = 0;
				return *this;
			}
			this->x /= l;
			this->y /= l;
			this->z /= l;
			return *this;
		}

		hkVector4f GetNormalized()
		{
			hkVector4f norm = *this;
			norm.Normalize();
			return norm;
		}

		float Dot(const hkVector4f& v)
		{
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}

		operator NiPoint3()
		{
			return NiPoint3(x, y, z);
		}

		// members
		hkReal x{ 0.0f };
		hkReal y{ 0.0f };
		hkReal z{ 0.0f };
		hkReal w{ 0.0f };
	};
	static_assert(sizeof(hkVector4f) == 0x10);

	using hkVector4 = hkVector4f;
}
