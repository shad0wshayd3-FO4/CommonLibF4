#include "RE/E/ExtraInstanceData.h"

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
		stl::emplace_vtable(this);
	}
}
