#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTDataBuffer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TBO_InstanceData.h"

namespace RE
{
	class BGSAttachParentArray;
	class INSTANCE_FILTER;

	namespace BGSMod
	{
		class ObjectIndexData;
	}

	class __declspec(novtable) BGSObjectInstanceExtra :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSObjectInstanceExtra };
		static constexpr auto VTABLE{ VTABLE::BGSObjectInstanceExtra };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kObjectInstance };

		BGSObjectInstanceExtra() :
			BSExtraData(TYPE)
		{
			REX::EMPLACE_VTABLE(this);
		}

		BGSObjectInstanceExtra(const BGSMod::Template::Item* a_item, TESForm* a_parentForm, const INSTANCE_FILTER* a_filter)
		{
			ctor(a_item, a_parentForm, a_filter);
		}

		static bool AttachModToReference(TESObjectREFR& a_ref, BGSMod::Attachment::Mod& a_mod, std::uint8_t a_attachIndex, std::uint8_t a_rank)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::AttachModToReference);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::AttachModToReference };
			return func(a_ref, a_mod, a_attachIndex, a_rank);
		}

		bool HasMod(const BGSMod::Attachment::Mod& a_mod)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::HasMod);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::HasMod };
			return func(this, a_mod);
		}

		void AddMod(const BGSMod::Attachment::Mod& a_newMod, std::uint8_t a_attachIndex, std::uint8_t a_rank, bool a_removeInvalidMods)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::AddMod);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::AddMod };
			return func(this, a_newMod, a_attachIndex, a_rank, a_removeInvalidMods);
		}

		void CreateBaseInstanceData(const TESBoundObject& a_object, BSTSmartPointer<TBO_InstanceData>& a_instanceData) const;

		[[nodiscard]] std::span<BGSMod::ObjectIndexData> GetIndexData() const noexcept;

		std::uint32_t RemoveInvalidMods(const BGSAttachParentArray* a_baseObjectParents)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::RemoveInvalidMods);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::RemoveInvalidMods };
			return func(this, a_baseObjectParents);
		}

		std::uint32_t RemoveMod(const BGSMod::Attachment::Mod* a_mod, std::uint8_t a_attachIndex)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::RemoveMod);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::RemoveMod };
			return func(this, a_mod, a_attachIndex);
		}

		std::uint32_t GetNumMods(bool a_ignoreCollections)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::GetNumMods);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::GetNumMods };
			return func(this, a_ignoreCollections);
		}

		// members
		const BSTDataBuffer<1>* values{ nullptr };  // 18
		std::uint16_t           itemIndex{ 0 };     // 20

	private:
		BGSObjectInstanceExtra* ctor(const BGSMod::Template::Item* a_item, TESForm* a_parentForm, const INSTANCE_FILTER* a_filter)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::ctor);
			static REL::Relocation<func_t> func{ ID::BGSObjectInstanceExtra::ctor };
			return func(this, a_item, a_parentForm, a_filter);
		}
	};
	static_assert(sizeof(BGSObjectInstanceExtra) == 0x28);
}
