#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSPreviewTransform :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPreviewTransform };
		static constexpr auto VTABLE{ VTABLE::BGSPreviewTransform };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'NRTP'; }     // 01
		void          InitializeDataComponent() override { transform = nullptr; }  // 02
		void          ClearDataComponent() override { return; }                    // 03
		void          InitComponent() override;                                    // 04
		void          CopyComponent(BaseFormComponent*) override { return; }       // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;        // 05

		// members
		BGSTransform* transform;  // 08
	};
	static_assert(sizeof(BGSPreviewTransform) == 0x10);
}
