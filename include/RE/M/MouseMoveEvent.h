#pragma once

namespace RE
{
	class __declspec(novtable) MouseMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MouseMoveEvent };
		static constexpr auto VTABLE{ VTABLE::MouseMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kMouseMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~MouseMoveEvent() = default;  // 00

		// members
		std::int32_t mouseInputX{ 0 };  // 38
		std::int32_t mouseInputY{ 0 };  // 3C
	};
	static_assert(sizeof(MouseMoveEvent) == 0x40);

	extern template MouseMoveEvent* InputEvent::As() noexcept;
	extern template const MouseMoveEvent* InputEvent::As() const noexcept;
}
