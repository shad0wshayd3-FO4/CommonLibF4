#include "RE/Bethesda/TESForms.h"

#include "RE/Bethesda/BSExtraData.h"
#include "RE/Bethesda/TESWorldSpace.h"

namespace RE
{
	bool BGSLocation::IsChild(const BGSLocation* a_possibleChild) const
	{
		if (a_possibleChild) {
			for (auto it = a_possibleChild->parentLoc; it; it = it->parentLoc) {
				if (this == it) {
					return true;
				}
			}
		}
		return false;
	}

	bool BGSLocation::IsParent(const BGSLocation* a_possibleParent) const
	{
		if (a_possibleParent) {
			for (auto it = parentLoc; it; it = it->parentLoc) {
				if (a_possibleParent == it) {
					return true;
				}
			}
		}
		return false;
	}

	TESWaterForm* TESObjectCELL::GetWaterType() const noexcept
	{
		const auto xWater = extraList ? extraList->GetByType<ExtraCellWaterType>() : nullptr;
		auto       water = xWater ? xWater->water : nullptr;
		if (!water) {
			water = IsExterior() && worldSpace ? worldSpace->GetWaterType() : nullptr;
			if (!water) {
				REL::Relocation<TESWaterForm**> defaultWater{ REL::ID(289864) };
				water = *defaultWater;
			}
		}

		return water;
	}
}
