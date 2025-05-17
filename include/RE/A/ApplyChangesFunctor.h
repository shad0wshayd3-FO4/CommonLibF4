#pragma once

#include "RE/B/BGSInventoryItem.h"

namespace RE
{
	class __declspec(novtable) ApplyChangesFunctor :
		public BGSInventoryItem::StackDataWriteFunctor  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__ApplyChangesFunctor };
		static constexpr auto VTABLE{ VTABLE::__ApplyChangesFunctor };

		// override
		virtual void WriteDataImpl(TESBoundObject& a_baseObj, BGSInventoryItem::Stack& a_stack) override  // 01
		{
			using func_t = decltype(&ApplyChangesFunctor::WriteDataImpl);
			static REL::Relocation<func_t> func{ ID::ApplyChangesFunctor::WriteDataImpl };
			return func(this, a_baseObj, a_stack);
		}

		// members
		BGSObjectInstanceExtra*        extra;             // 10
		TESBoundObject*                object;            // 18
		const BGSMod::Attachment::Mod* mod;               // 20
		std::uint8_t                   rank;              // 28
		bool                           remove;            // 29
		bool                           excludeTemporary;  // 2A
		std::int8_t                    favoriteIndex;     // 2B
	};
	static_assert(sizeof(ApplyChangesFunctor) == 0x30);
}
