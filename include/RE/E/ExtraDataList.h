#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BaseExtraList.h"
#include "RE/E/EXTRA_DATA_TYPE.h"
#include "RE/M/MemoryManager.h"
#include "RE/N/NiPoint.h"
#include "RE/T/TBO_InstanceData.h"

namespace RE
{
	class BGSObjectInstanceExtra;
	class BGSPrimitive;

	namespace detail
	{
		template <class T>
		concept ExtraDataListConstraint =
			std::derived_from<T, BSExtraData> &&
			!std::is_pointer_v<T> &&
			!std::is_reference_v<T>;
	}

	class ExtraDataList :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		F4_HEAP_REDEFINE_NEW(ExtraDataList);

		void AddExtra(BSExtraData* a_extra)
		{
			const BSAutoWriteLock l{ extraRWLock };
			extraData.AddExtra(a_extra);
		}

		stl::observer<TBO_InstanceData*> CreateInstanceData(TESBoundObject* a_object, bool a_generateName)
		{
			using func_t = decltype(&ExtraDataList::CreateInstanceData);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::CreateInstanceData };
			return func(this, a_object, a_generateName);
		}

		[[nodiscard]] BSExtraData* GetByType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			const BSAutoReadLock l{ extraRWLock };
			return extraData.GetByType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] T* GetByType() const noexcept
		{
			return static_cast<T*>(GetByType(T::TYPE));
		}

		[[nodiscard]] BGSMod::Attachment::Mod* GetLegendaryMod()
		{
			using func_t = decltype(&ExtraDataList::GetLegendaryMod);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::GetLegendaryMod };
			return func(this);
		}

		[[nodiscard]] bool HasType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			const BSAutoReadLock l{ extraRWLock };
			return extraData.HasType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] bool HasType() const noexcept
		{
			return HasType(T::TYPE);
		}

		std::unique_ptr<BSExtraData> RemoveExtra(EXTRA_DATA_TYPE a_type)
		{
			const BSAutoWriteLock l{ extraRWLock };
			return extraData.RemoveExtra(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		std::unique_ptr<T> RemoveExtra()
		{
			return std::unique_ptr<T>{ static_cast<T*>(RemoveExtra(T::TYPE).release()) };
		}

		bool SetBendableSplineInfo(float* a_thickness, float* a_slack, NiPoint3* a_halfExtents = nullptr, bool* a_detachedEnd = nullptr)
		{
			using func_t = decltype(&ExtraDataList::SetBendableSplineInfo);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetBendableSplineInfo };
			return func(this, a_thickness, a_slack, a_halfExtents, a_detachedEnd);
		}

		void SetDisplayNameFromInstanceData(BGSObjectInstanceExtra* a_instExtra, TESBoundObject* a_object, const BSTSmartPointer<TBO_InstanceData>& a_data)
		{
			using func_t = decltype(&ExtraDataList::SetDisplayNameFromInstanceData);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetDisplayNameFromInstanceData };
			return func(this, a_instExtra, a_object, a_data);
		}

		void SetOverrideName(const char* a_name)
		{
			using func_t = decltype(&ExtraDataList::SetOverrideName);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetOverrideName };
			return func(this, a_name);
		}

		void SetStartingWorldOrCell(TESForm* a_form)
		{
			using func_t = decltype(&ExtraDataList::SetStartingWorldOrCell);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetStartingWorldOrCell };
			return func(this, a_form);
		}

		float GetHealthPerc()
		{
			using func_t = decltype(&ExtraDataList::GetHealthPerc);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::GetHealthPerc };
			return func(this);
		}

		void SetHealthPerc(float a_healthPerc)
		{
			using func_t = decltype(&ExtraDataList::SetHealthPerc);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetHealthPerc };
			return func(this, a_healthPerc);
		}

		bool ClearFavorite()
		{
			using func_t = decltype(&ExtraDataList::ClearFavorite);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::ClearFavorite };
			return func(this);
		}

		bool IsFavorite()
		{
			using func_t = decltype(&ExtraDataList::IsFavorite);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::IsFavorite };
			return func(this);
		}

		bool IsDamaged()
		{
			using func_t = decltype(&ExtraDataList::IsDamaged);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::IsDamaged };
			return func(this);
		}

		typedef bool (*ComparisonQualifier)(const BSExtraData*);
		bool CompareList(const ExtraDataList* a_compare, ComparisonQualifier a_qualifier)
		{
			using func_t = decltype(&ExtraDataList::CompareList);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::CompareList };
			return func(this, a_compare, a_qualifier);
		}

		void SetFavorite(char a_quickKeyIndex)
		{
			using func_t = decltype(&ExtraDataList::SetFavorite);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::SetFavorite };
			return func(this, a_quickKeyIndex);
		}

		BGSPrimitive* GetPrimitive()
		{
			using func_t = decltype(&ExtraDataList::GetPrimitive);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::GetPrimitive };
			return func(this);
		}

		// members
		BaseExtraList           extraData;    // 08
		mutable BSReadWriteLock extraRWLock;  // 20
	};
	static_assert(sizeof(ExtraDataList) == 0x28);
}
