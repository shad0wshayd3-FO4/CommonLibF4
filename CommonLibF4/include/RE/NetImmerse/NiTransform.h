#pragma once

#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	class NiTransform
	{
	public:
		static const NiTransform ZERO;
		static const NiTransform IDENTITY;

		NiTransform() noexcept = default;
		NiTransform(const NiMatrix3& a_rotate, const NiPoint3& a_translate, const float a_scale) noexcept;

		bool        operator==(const NiTransform& a_rhs) const noexcept;
		bool        operator!=(const NiTransform& a_rhs) const noexcept;
		NiTransform operator*(const NiTransform& a_rhs) const noexcept;
		NiPoint3    operator*(const NiPoint3& a_rhs) const noexcept;

		NiTransform  Invert() const noexcept;
		NiTransform& MakeIdentity() noexcept;
		NiTransform& MakeInvert() noexcept;

		// members
		NiMatrix3 rotate;         // 00
		NiPoint3  translate;      // 30
		float     scale{ 1.0F };  // 3C
	};
	static_assert(sizeof(NiTransform) == 0x40);
}

template <>
struct std::formatter<RE::NiTransform>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiTransform& a_transform, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "<{}, {}>", a_transform.rotate, a_transform.translate, a_transform.scale);
	}
};
