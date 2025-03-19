#pragma once

namespace RE
{
	class __declspec(novtable) GridArray
	{
	public:
		static constexpr auto RTTI{ RTTI::GridArray };
		static constexpr auto VTABLE{ VTABLE::GridArray };

		virtual ~GridArray(); // 00

		// add
		virtual void DetachAll();                                                                                           // 01
		virtual void KillAll();                                                                                             // 02
		virtual bool SetCenter(std::int32_t a_x, std::int32_t a_y);                                                         // 03
		virtual void Shift(std::int32_t a_x, std::int32_t a_y);                                                             // 04
		virtual void Detach(std::uint32_t a_x, std::uint32_t a_y) = 0;                                                      // 05
		virtual void ClearItem(std::uint32_t a_x, std::uint32_t a_y) = 0;                                                   // 06
		virtual void MoveItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) = 0;  // 07
		virtual void SwapItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) = 0;  // 08

		// members
		std::int32_t centerX;	 // 08
		std::int32_t centerY;	 // 0C
		std::uint32_t dimension; // 10
	};
	static_assert(sizeof(GridArray) == 0x18);
}
