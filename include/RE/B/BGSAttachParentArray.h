#pragma once

namespace RE
{
	class __declspec(novtable) BGSAttachParentArray :
		public BaseFormComponent,                                    // 00
		public BGSTypedKeywordValueArray<KeywordType::kAttachPoint>  // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttachParentArray };
		static constexpr auto VTABLE{ VTABLE::BGSAttachParentArray };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'APPA'; }  // 01
		void          InitializeDataComponent() override { return; }            // 02
		void          ClearDataComponent() override;                            // 03
		void          CopyComponent(BaseFormComponent*) override { return; }    // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;     // 05

		void SetParentGroupNumber(BGSKeyword* a_parent, std::uint32_t a_groupID)
		{
			using func_t = decltype(&BGSAttachParentArray::SetParentGroupNumber);
			static REL::Relocation<func_t> func{ REL::ID(1412266) };
			return func(this, a_parent, a_groupID);
		}
	};
	static_assert(sizeof(BGSAttachParentArray) == 0x18);
}
