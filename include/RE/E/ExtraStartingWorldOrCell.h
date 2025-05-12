#pragma once

namespace RE
{
	class __declspec(novtable) ExtraStartingWorldOrCell :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraStartingWorldOrCell };
		static constexpr auto VTABLE{ VTABLE::ExtraStartingWorldOrCell };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kStartingWorldOrCell };

		ExtraStartingWorldOrCell() :
			ExtraStartingWorldOrCell(nullptr)
		{
		}

		ExtraStartingWorldOrCell(TESForm* a_form) :
			BSExtraData(TYPE),
			startingWorldOrCell(a_form)
		{
			stl::emplace_vtable(this);
		}

		// members
		TESForm* startingWorldOrCell;  // 18
	};
	static_assert(sizeof(ExtraStartingWorldOrCell) == 0x20);
}
