#pragma once

#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) MultitouchInterface :
		public State  // 00
	{
	public:
		enum class MultitouchInputMode : std::int32_t
		{
			kNone = 0,
			kTouchPoint = 0x1,
			kGesture = 0x2,
			kMixed = (kTouchPoint | kGesture)
		};

		enum GestureMask : std::int32_t
		{
			kMTG_None = 0,
			kMTG_Pan = 0x1,
			kMTG_Zoom = 0x2,
			kMTG_Rotate = 0x4,
			kMTG_Swipe = 0x8
		};

		MultitouchInterface() :
			State(StateType::kMultitouchInterface)
		{}

		virtual std::uint32_t GetMaxTouchPoints() const = 0;
		virtual std::uint32_t GetSupportedGesturesMask() const = 0;
		virtual bool          SetMultitouchInputMode(MultitouchInputMode a_inputMode) = 0;
	};
}
