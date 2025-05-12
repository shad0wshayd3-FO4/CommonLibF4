#pragma once

namespace RE
{
	class __declspec(novtable) ExtraInstanceData :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraInstanceData };
		static constexpr auto VTABLE{ VTABLE::ExtraInstanceData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kInstanceData };

		ExtraInstanceData();
		ExtraInstanceData(const TESBoundObject* a_base, BSTSmartPointer<TBO_InstanceData> a_data);

		// members
		const TESBoundObject* base{ nullptr };  // 18
		BSTSmartPointer<TBO_InstanceData> data;             // 20
	};
	static_assert(sizeof(ExtraInstanceData) == 0x28);
}
