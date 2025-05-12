#pragma once

namespace RE
{
	class __declspec(novtable) BGSRefAlias :
		public BGSBaseAlias  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSRefAlias };
		static constexpr auto VTABLE{ VTABLE::BGSRefAlias };
		static constexpr auto TYPE{ "Ref"sv };

		enum class FILL_TYPE
		{
			kConditions = 0x0,
			kForced = 0x1,
			kFromAlias = 0x2,
			kFromEvent = 0x3,
			kCreated = 0x4,
			kFromExternal = 0x5,
			kUniqueActor = 0x6,
			kNearAlias = 0x7,
		};

		struct GenericFillData
		{
		public:
			// members
			std::uint64_t data[3];
		};
		static_assert(sizeof(GenericFillData) == 0x18);

		// members
		GenericFillData fillData;    // 28
		TESCondition*   conditions;  // 40
	};
	static_assert(sizeof(BGSRefAlias) == 0x48);
}
