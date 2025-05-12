#pragma once

namespace RE
{
	class PipboyRadioController
	{
	public:
		// members
		float chaseStation;  // 00
	};
	static_assert(sizeof(PipboyRadioController) == 0x04);
}
