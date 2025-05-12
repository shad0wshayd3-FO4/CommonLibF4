#pragma once

namespace RE
{
	class __declspec(novtable) RepairFailureCallback :
		public ExamineConfirmMenu::ICallback  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__RepairFailureCallback };
		static constexpr auto VTABLE{ VTABLE::__RepairFailureCallback };

		RepairFailureCallback(ExamineMenu* a_thisMenu) :
			ExamineConfirmMenu::ICallback(a_thisMenu)
		{
			stl::emplace_vtable(this);
		}

		virtual ~RepairFailureCallback() = default;  // 00

		// override
		virtual void OnAccept() override;  // 01

		F4_HEAP_REDEFINE_NEW(RepairFailureCallback);
	};
	static_assert(sizeof(RepairFailureCallback) == 0x10);
}
