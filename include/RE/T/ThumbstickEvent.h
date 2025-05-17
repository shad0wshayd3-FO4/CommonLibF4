#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
	class __declspec(novtable) ThumbstickEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ThumbstickEvent };
		static constexpr auto VTABLE{ VTABLE::ThumbstickEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kThumbstick };

		enum THUMBSTICK_ID : std::int32_t
		{
			kLeft = 0xB,
			kRight = 0xC,
		};

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ThumbstickEvent() = default;  // 00

		// members
		float         xValue{ 0.0F };                   // 38
		float         yValue{ 0.0F };                   // 3C
		DIRECTION_VAL prevDir{ DIRECTION_VAL::kNone };  // 40
		DIRECTION_VAL currDir{ DIRECTION_VAL::kNone };  // 44
	};
	static_assert(sizeof(ThumbstickEvent) == 0x48);

	extern template ThumbstickEvent*       InputEvent::As() noexcept;
	extern template const ThumbstickEvent* InputEvent::As() const noexcept;
}
