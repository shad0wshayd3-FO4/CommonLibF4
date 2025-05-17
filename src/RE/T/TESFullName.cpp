#include "RE/T/TESFullName.h"

#include "RE/C/CHANGE_TYPES.h"
#include "RE/F/FormUtil.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESObjectCELL.h"

namespace RE
{
	std::string_view TESFullName::GetFullName(const TESForm& a_form, bool a_strict)
	{
		if (const auto fullName = a_form.As<TESFullName>()) {
			const auto name = fullName->GetFullName();
			return name ? name : ""sv;
		} else {
			if (a_strict) {
				switch (a_form.GetFormType()) {
					case ENUM_FORM_ID::kKYWD:  // BGSKeyword
					case ENUM_FORM_ID::kLCRT:  // BGSLocationRefType
					case ENUM_FORM_ID::kAACT:  // BGSAction
					case ENUM_FORM_ID::kLIGH:  // TESObjectLIGH
					case ENUM_FORM_ID::kSTAT:  // TESObjectSTAT
					case ENUM_FORM_ID::kSCOL:  // BGSStaticCollection
					case ENUM_FORM_ID::kMSTT:  // BGSMovableStatic
					case ENUM_FORM_ID::kFLST:  // BGSListForm
						break;
					default:
						return ""sv;
				}
			}

			const auto& map = GetSparseFullNameMap();
			const auto  it = map.find(std::addressof(a_form));
			return it != map.end() ? it->second : ""sv;
		}
	}

	void TESFullName::SetFullName(TESForm& a_form, std::string_view a_fullName)
	{
		if (const auto full = a_form.As<TESFullName>()) {
			full->fullName = a_fullName;
			if (const auto actor = a_form.As<TESActorBase>()) {
				actor->AddChange(CHANGE_TYPES::kActorBaseFullName);
			} else if (const auto cell = a_form.As<TESObjectCELL>()) {
				cell->AddChange(CHANGE_TYPES::kCellFullname);
			} else {
				a_form.AddChange(CHANGE_TYPES::kBaseObjectFullName);
			}
		}
	}
}
