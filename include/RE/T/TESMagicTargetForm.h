#pragma once

namespace RE
{
	class TESMagicTargetForm
	{
	public:
		static constexpr auto RTTI{ RTTI::TESMagicTargetForm };
	};
	static_assert(std::is_empty_v<TESMagicTargetForm>);
}
