#pragma once

#include "RE/I/InputEvent.h"

namespace RE
{
	class __declspec(novtable) CharacterEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CharacterEvent };
		static constexpr auto VTABLE{ VTABLE::CharacterEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kChar };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CharacterEvent() = default;  // 00

		// members
		std::uint32_t charCode{ 0 };  // 28
	};
	static_assert(sizeof(CharacterEvent) == 0x30);

	extern template CharacterEvent*       InputEvent::As() noexcept;
	extern template const CharacterEvent* InputEvent::As() const noexcept;
}
