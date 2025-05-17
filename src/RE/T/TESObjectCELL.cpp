#include "RE/T/TESObjectCELL.h"

#include "RE/E/ExtraCellWaterType.h"
#include "RE/E/ExtraDataList.h"
#include "RE/T/TESWorldSpace.h"

namespace RE
{
	TESWaterForm* TESObjectCELL::GetWaterType() const noexcept
	{
		const auto xWater = extraList ? extraList->GetByType<ExtraCellWaterType>() : nullptr;
		auto       water = xWater ? xWater->water : nullptr;
		if (!water) {
			water = IsExterior() && worldSpace ? worldSpace->GetWaterType() : nullptr;
			if (!water) {
				static REL::Relocation<TESWaterForm**> defaultWater{ ID::TESObjectCELL::DefaultWater };
				water = *defaultWater;
			}
		}

		return water;
	}
}
