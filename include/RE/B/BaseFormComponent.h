#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class __declspec(novtable) BaseFormComponent
	{
	public:
		static constexpr auto RTTI{ RTTI::BaseFormComponent };
		static constexpr auto VTABLE{ VTABLE::BaseFormComponent };

		virtual ~BaseFormComponent() = default;  // 00

		F4_HEAP_REDEFINE_NEW(BaseFormComponent);

		// add
		virtual std::uint32_t GetFormComponentType() const { return 0; }                                                                // 01
		virtual void          InitializeDataComponent() = 0;                                                                            // 02
		virtual void          ClearDataComponent() = 0;                                                                                 // 03
		virtual void          InitComponent() { return; }                                                                               // 04
		virtual void          CopyComponent([[maybe_unused]] BaseFormComponent* a_copy) { return; }                                     // 06
		virtual void          CopyComponent([[maybe_unused]] BaseFormComponent* a_copy, [[maybe_unused]] TESForm* a_owner) { return; }  // 05
	};
	static_assert(sizeof(BaseFormComponent) == 0x8);
}
