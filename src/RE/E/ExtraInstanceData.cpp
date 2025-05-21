#include "RE/E/ExtraInstanceData.h"

#include "RE/T/TBO_InstanceData.h"

namespace RE
{
	ExtraInstanceData::ExtraInstanceData() :
		ExtraInstanceData(nullptr, nullptr)
	{}

	ExtraInstanceData::ExtraInstanceData(const TESBoundObject* a_base, BSTSmartPointer<TBO_InstanceData> a_data) :
		BSExtraData(TYPE),
		base(a_base),
		data(std::move(a_data))
	{
		REX::EMPLACE_VTABLE(this);
	}
}
