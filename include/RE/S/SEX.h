#pragma once

namespace RE
{
	enum class SEX : std::uint32_t
	{
		kNone = static_cast<std::underlying_type_t<SEX>>(-1),
		kMale = 0x0,
		kFemale = 0x1,

		kTotal = 0x2
	};
}

template <>
struct std::formatter<RE::SEX>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::SEX& a_sex, FormatContext& a_ctx) const
	{
		switch (a_sex) {
			case RE::SEX::kNone:
				return format_to(a_ctx.out(), "None");
			case RE::SEX::kMale:
				return format_to(a_ctx.out(), "Male");
			case RE::SEX::kFemale:
				return format_to(a_ctx.out(), "Female");
		}

		return format_to(a_ctx.out(), "Unknown");
	}
};
