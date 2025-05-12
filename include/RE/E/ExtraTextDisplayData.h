#pragma once

namespace RE
{
	class __declspec(novtable) ExtraTextDisplayData :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraTextDisplayData };
		static constexpr auto VTABLE{ VTABLE::ExtraTextDisplayData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kTextDisplayData };

		enum class DisplayDataType
		{
			kUninitialized = -1,
			kCustomName = -2
		};

		[[nodiscard]] const BSFixedStringCS& GetDisplayName(TESBoundObject* a_baseObject)
		{
			using func_t = decltype(&ExtraTextDisplayData::GetDisplayName);
			static REL::Relocation<func_t> func{ REL::ID(1523343) };
			return func(this, a_baseObject);
		}

		// members
		BSFixedStringCS                              displayName;       // 18
		BGSMessage*                                  displayNameText;   // 20
		TESQuest*                                    ownerQuest;        // 28
		REX::EnumSet<DisplayDataType, std::int32_t>  ownerInstance;     // 30
		BSTArray<BSTTuple<BSFixedString, TESForm*>>* textPairs;         // 38
		std::uint16_t                                customNameLength;  // 40
	};
	static_assert(sizeof(ExtraTextDisplayData) == 0x48);
}
