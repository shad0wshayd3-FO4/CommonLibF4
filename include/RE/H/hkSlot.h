#pragma once

namespace RE
{
	struct hkSlot
	{
		static constexpr auto RTTI{ RTTI::hkSlot };
		static constexpr auto VTABLE{ VTABLE::hkSlot };

		virtual ~hkSlot();

		// add
		virtual hkBool32 MatchMethod(const void* a_methodData, std::int32_t a_methodLength) const = 0;

		// members
		mutable hkSlot* next;
		void*           object;
	};
}
