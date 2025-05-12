#pragma once

namespace RE
{
	namespace UIUtils
	{
		inline void UpdateGamepadDependentButtonCodes(bool a_usingGamepad)
		{
			using func_t = decltype(&UpdateGamepadDependentButtonCodes);
			static REL::Relocation<func_t> func{ REL::ID(190238) };
			return func(a_usingGamepad);
		}
	}
}
