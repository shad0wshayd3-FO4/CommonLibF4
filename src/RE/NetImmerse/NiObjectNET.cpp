#include "RE/NetImmerse/NiObjectNET.h"

#include "RE/NetImmerse/NiTimeController.h"

namespace RE
{
	NiObjectNET::NiObjectNET() { stl::emplace_vtable(this); }

	NiObjectNET::~NiObjectNET() {}

	NiExtraData* NiObjectNET::GetExtraData(BSFixedString a_key) const noexcept
	{
		if (extra) {
			for (auto it = extra->begin(); it != extra->end(); ++it) {
				if ((*it)->name == a_key) {
					return *it;
				}
			}
		}

		return nullptr;
	}
	// NOLINT(modernize-use-equals-default)
}
