#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class __declspec(novtable) BGSDefaultObject :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDefaultObject };
		static constexpr auto VTABLE{ VTABLE::BGSDefaultObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDFOB };

		BGSDefaultObject(const char* a_name, ENUM_FORM_ID a_formType, const char* a_description)
		{
			ctor(a_name, a_formType, a_description);
		}

		[[nodiscard]] static BSTArray<BGSDefaultObject*>* GetSingleton()
		{
			static REL::Relocation<BSTArray<BGSDefaultObject*>**> singleton{ ID::BGSDefaultObject::Singleton };
			return *singleton;
		}

		template <class T = TESForm>
		[[nodiscard]] T* GetForm()
		{
			return form ? form->As<T>() : nullptr;
		}

		// members
		TESForm*      form;          // 20
		ENUM_FORM_ID  type;          // 28
		BSFixedString formEditorID;  // 30

	private:
		BGSDefaultObject* ctor(const char* a_name, ENUM_FORM_ID a_formType, const char* a_description)
		{
			using func_t = decltype(&BGSDefaultObject::ctor);
			static REL::Relocation<func_t> func{ ID::BGSDefaultObject::ctor };
			return func(this, a_name, a_formType, a_description);
		}
	};
	static_assert(sizeof(BGSDefaultObject) == 0x38);
}
