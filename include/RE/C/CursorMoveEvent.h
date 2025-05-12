#pragma once

namespace RE
{
	class __declspec(novtable) CursorMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CursorMoveEvent };
		static constexpr auto VTABLE{ VTABLE::CursorMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kCursorMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CursorMoveEvent() = default;  // 00

		// members
		std::int32_t cursorPosX{ 0 };  // 38
		std::int32_t cursorPosY{ 0 };  // 3C
	};
	static_assert(sizeof(CursorMoveEvent) == 0x40);

	extern template CursorMoveEvent* InputEvent::As() noexcept;
	extern template const CursorMoveEvent* InputEvent::As() const noexcept;
}
