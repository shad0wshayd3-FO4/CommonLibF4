#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSSoundTagComponent :
		public BaseFormComponent  // 0
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundTagComponent };
		static constexpr auto VTABLE{ VTABLE::BGSSoundTagComponent };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'CTAC'; }  // 01
		void          InitializeDataComponent() override { return; }            // 02
		void          ClearDataComponent() override;                            // 03
		void          InitComponent() override;                                 // 04
		void          CopyComponent(BaseFormComponent*) override { return; }    // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;     // 05
	};
	static_assert(sizeof(BGSSoundTagComponent) == 0x8);
}
