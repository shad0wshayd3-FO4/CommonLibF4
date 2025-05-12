#pragma once

namespace RE
{
	class DefaultObjectFormFactory :
		public IFormFactory  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__DefaultObjectFormFactory };
		static constexpr auto VTABLE{ VTABLE::__DefaultObjectFormFactory };

		virtual ~DefaultObjectFormFactory();  // 00

		// override
		[[nodiscard]] TESForm* DoCreate() override  // 01
		{
			return new BGSDefaultObject("", ENUM_FORM_ID::kNONE, "");
		}

		[[nodiscard]] const char*          GetFormName() const override { return "DefaultObject"; }    // 02
		[[nodiscard]] ENUM_FORM_ID         GetFormID() const override { return ENUM_FORM_ID::kDFOB; }  // 03
		[[nodiscard]] const char*          GetObjectName() const override { return "DefaultObject"; }  // 04
		[[nodiscard]] OBJECT_TYPE          GetObjectType() const override;                             // 05
		[[nodiscard]] OBJECT_CATEGORY_TYPE GetObjectCategory() const override;                         // 06

		[[nodiscard]] static BGSDefaultObject* Create(const char* a_name, const char* a_description, ENUM_FORM_ID a_formType)
		{
			auto form = new BGSDefaultObject(a_name, a_formType, a_description);
			return form;
		}

		[[nodiscard]] static BGSDefaultObject* Create(const char* a_name, ENUM_FORM_ID a_formType)
		{
			return Create(a_name, "", a_formType);
		}
	};
	static_assert(sizeof(DefaultObjectFormFactory) == 0x08);
}
