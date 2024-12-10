#pragma once

#include "RE/Bethesda/TESBoundObjects.h"

namespace RE
{
	namespace ActorUtils
	{
		class __declspec(novtable) ArmorRatingVisitorBase
		{
		public:
			static constexpr auto RTTI{ RTTI::ActorUtils__ArmorRatingVisitorBase };
			static constexpr auto VTABLE{ VTABLE::ActorUtils__ArmorRatingVisitorBase };

			ArmorRatingVisitorBase()
			{
				stl::emplace_vtable(this);
			}

			virtual bool ShouldProcess(TESBoundObject*) { return 1; };  // 00
			virtual void PostPRocess(TESBoundObject*){};                // 01

			Actor* actor;          // 08
			float  rating;         // 10
			float  armorPerks;     // 14
			bool   checkEquipped;  // 18

			void ctor(const Actor* a_actor, bool a_checkEquipped)
			{
				using func_t = decltype(&ArmorRatingVisitorBase::ctor);
				REL::Relocation<func_t> func{ REL::ID(2227205) };
				return func(this, a_actor, a_checkEquipped);
			}

			ArmorRatingVisitorBase(const Actor* a_actor, bool a_checkEquipped)
			{
				ctor(a_actor, a_checkEquipped);
			}

			std::int64_t operator()(const BGSInventoryItem* a_item, std::uint32_t a_stackID)
			{
				using func_t = decltype(&ArmorRatingVisitorBase::operator());
				REL::Relocation<func_t> func{ REL::ID(2227206) };
				return func(this, a_item, a_stackID);
			}
		};
		static_assert(offsetof(ArmorRatingVisitorBase, rating) == 0x10);
		static_assert(sizeof(ArmorRatingVisitorBase) == 0x20);

		class __declspec(novtable) ArmorRatingVisitor :
			public ArmorRatingVisitorBase  // 00
		{
			static constexpr auto RTTI{ RTTI::ActorUtils__ArmorRatingVisitor };
			static constexpr auto VTABLE{ VTABLE::ActorUtils__ArmorRatingVisitor };

			BSScrapArray<TESBoundObject*> foundArmor;  // 20
		};
		static_assert(sizeof(ArmorRatingVisitor) == 0x40);
	}
}
