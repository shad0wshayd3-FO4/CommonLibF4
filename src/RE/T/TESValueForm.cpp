#include "RE/T/TESValueForm.h"

namespace RE
{
	void TESValueForm::SetFormValue(TESForm& a_form, std::int32_t a_value)
	{
		const auto val = a_form.As<TESValueForm>();
		if (val) {
			val->value = a_value;
			a_form.AddChange(CHANGE_TYPES::kBaseObjectValue);
		}
	}
}
