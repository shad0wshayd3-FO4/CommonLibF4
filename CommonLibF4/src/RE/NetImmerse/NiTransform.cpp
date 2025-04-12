#include "RE/NetImmerse/NiTransform.h"

namespace RE
{
	const NiTransform NiTransform::ZERO = { NiMatrix3::ZERO, NiPoint3::ZERO, 0.0F };
	const NiTransform NiTransform::IDENTITY = { NiMatrix3::IDENTITY, NiPoint3::ZERO, 1.0F };

	NiTransform::NiTransform(const NiMatrix3& a_rotate, const NiPoint3& a_translate, const float a_scale) noexcept :
		rotate(a_rotate), translate(a_translate), scale(a_scale)
	{}

	bool NiTransform::operator==(const NiTransform& a_rhs) const noexcept
	{
		return (rotate == a_rhs.rotate) && (translate == a_rhs.translate) && (scale == a_rhs.scale);
	}

	bool NiTransform::operator!=(const NiTransform& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	NiTransform NiTransform::operator*(const NiTransform& a_rhs) const noexcept
	{
		return NiTransform(rotate * a_rhs.rotate, translate + (rotate * a_rhs.translate) * scale, scale * a_rhs.scale);
	}

	NiPoint3 NiTransform::operator*(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(((rotate * a_rhs) * scale) + translate);
	}

	NiTransform NiTransform::Invert() const noexcept
	{
		NiTransform transform(*this);
		return transform.MakeInvert();
	}

	NiTransform& NiTransform::MakeIdentity() noexcept
	{
		rotate = NiMatrix3::IDENTITY;
		translate = NiPoint3::ZERO;
		scale = 1.0F;
		return *this;
	}

	NiTransform& NiTransform::MakeInvert() noexcept
	{
		rotate = rotate.Transpose();
		scale = 1.0f / scale;
		translate = (rotate * -translate) * scale;
		return *this;
	}
}
