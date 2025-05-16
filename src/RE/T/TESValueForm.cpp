#include "RE/T/TESValueForm.h"

#include "RE/C/CHANGE_TYPES.h"
#include "RE/T/TESForm.h"

namespace RE
{
	void TESValueForm::SetFormValue(TESForm& a_form, std::int32_t a_value)
	{
		if (const auto val = a_form.As<TESValueForm>()) {
			val->value = a_value;
			a_form.AddChange(CHANGE_TYPES::kBaseObjectValue);
		}
	}
}
