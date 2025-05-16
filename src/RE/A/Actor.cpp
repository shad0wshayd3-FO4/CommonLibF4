#include "RE/A/Actor.h"

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESNPC.h"

namespace RE
{
	TESNPC* Actor::GetNPC() const noexcept
	{
		const auto objRef = GetObjectReference();
		assert(objRef->GetFormType() == ENUM_FORM_ID::kNPC_);
		return static_cast<TESNPC*>(objRef);
	}
}
