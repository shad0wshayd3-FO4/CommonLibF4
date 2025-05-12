#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct __declspec(novtable) IMovementPlayerControls :
		public IMovementInterface  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IMovementPlayerControls };
		static constexpr auto VTABLE{ VTABLE::IMovementPlayerControls };

		// add
		virtual void GetControllerOutput(std::uint32_t a_numericID, PlayerControlsMovementData& a_normalizedOutputData) = 0;  // 01
	};
	static_assert(sizeof(IMovementPlayerControls) == 0x8);
}
