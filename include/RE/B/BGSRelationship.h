#pragma once

namespace RE
{
	class __declspec(novtable) BGSRelationship :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSRelationship };
		static constexpr auto VTABLE{ VTABLE::BGSRelationship };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kRELA };

		// members
		TESNPC*             npc1;        // 20
		TESNPC*             npc2;        // 28
		BGSAssociationType* assocType;   // 30
		std::uint32_t       packedData;  // 38
	};
	static_assert(sizeof(BGSRelationship) == 0x40);
}
