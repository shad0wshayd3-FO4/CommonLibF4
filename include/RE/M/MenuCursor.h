#pragma once

#include "RE/B/BSInputEventSingleUser.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class __declspec(novtable) MenuCursor :
		public BSInputEventSingleUser,      // 00
		public BSTSingletonSDM<MenuCursor>  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::MenuCursor };
		static constexpr auto VTABLE{ VTABLE::MenuCursor };

		[[nodiscard]] static MenuCursor* GetSingleton()
		{
			static REL::Relocation<MenuCursor**> singleton{ ID::MenuCursor::Singleton };
			return *singleton;
		}

		void CenterCursor()
		{
			using func_t = decltype(&MenuCursor::CenterCursor);
			static REL::Relocation<func_t> func{ ID::MenuCursor::CenterCursor };
			return func(this);
		}

		void ClearConstraints() noexcept
		{
			leftConstraintPct = 0.0f;
			rightConstraintPct = 0.0f;
			topConstraintPct = 0.0f;
			bottomConstraintPct = 0.0f;
		}

		void ConstrainForPipboy();
		void ConstrainForPipboyPA();

		void RegisterCursor()
		{
			using func_t = decltype(&MenuCursor::RegisterCursor);
			static REL::Relocation<func_t> func{ ID::MenuCursor::RegisterCursor };
			return func(this);
		}

		void SetCursorConstraintsRaw(std::uint32_t a_tlx, std::uint32_t a_tly, std::uint32_t a_width, std::uint32_t a_height)
		{
			using func_t = decltype(&MenuCursor::SetCursorConstraintsRaw);
			static REL::Relocation<func_t> func{ ID::MenuCursor::SetCursorConstraintsRaw };
			return func(this, a_tlx, a_tly, a_width, a_height);
		}

		void UnregisterCursor()
		{
			using func_t = decltype(&MenuCursor::UnregisterCursor);
			static REL::Relocation<func_t> func{ ID::MenuCursor::UnregisterCursor };
			return func(this);
		}

		// members
		std::int32_t  cursorPosX;                  // 24
		std::int32_t  cursorPosY;                  // 28
		std::int32_t  minCursorX;                  // 2C
		std::int32_t  minCursorY;                  // 30
		std::int32_t  maxCursorX;                  // 34
		std::int32_t  maxCursorY;                  // 38
		float         leftConstraintPct;           // 3C
		float         rightConstraintPct;          // 40
		float         topConstraintPct;            // 44
		float         bottomConstraintPct;         // 48
		float         gamepadCursorSpeed;          // 4C
		std::uint32_t registeredCursors;           // 50
		bool          forceOSCursorPos;            // 54
		bool          allowGamepadCursorOverride;  // 55
	};
	static_assert(sizeof(MenuCursor) == 0x58);
}
