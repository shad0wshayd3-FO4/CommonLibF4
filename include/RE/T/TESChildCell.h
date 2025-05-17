#pragma once

namespace RE
{
	class __declspec(novtable) TESChildCell
	{
	public:
		static constexpr auto RTTI{ RTTI::TESChildCell };
		static constexpr auto VTABLE{ VTABLE::TESChildCell };

		virtual ~TESChildCell() = default;  // 00

		// add
		virtual TESObjectCELL* GetSaveParentCell() const = 0;  // 01
	};
	static_assert(sizeof(TESChildCell) == 0x8);
}
