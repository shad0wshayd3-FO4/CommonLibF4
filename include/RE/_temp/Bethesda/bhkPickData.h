#pragma once

#include "RE/Bethesda/MemoryManager.h"
#include "RE/Bethesda/bhkCharacterController.h"
#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpCollisionResult.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	struct bhkPickData
	{
	public:
		bhkPickData()
		{
			typedef bhkPickData*           func_t(bhkPickData*);
			static REL::Relocation<func_t> func{ REL::ID(526783) };
			func(this);
		}

		F4_HEAP_REDEFINE_NEW(bhkPickData);

		void SetStartEnd(const NiPoint3& start, const NiPoint3& end)
		{
			using func_t = decltype(&bhkPickData::SetStartEnd);
			static REL::Relocation<func_t> func{ REL::ID(747470) };
			return func(this, start, end);
		}

		void Reset()
		{
			using func_t = decltype(&bhkPickData::Reset);
			static REL::Relocation<func_t> func{ REL::ID(438299) };
			return func(this);
		}

		bool HasHit()
		{
			using func_t = decltype(&bhkPickData::HasHit);
			static REL::Relocation<func_t> func{ REL::ID(1181584) };
			return func(this);
		}

		float GetHitFraction()
		{
			using func_t = decltype(&bhkPickData::GetHitFraction);
			static REL::Relocation<func_t> func{ REL::ID(476687) };
			return func(this);
		}

		int32_t GetAllCollectorRayHitSize()
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitSize);
			static REL::Relocation<func_t> func{ REL::ID(1288513) };
			return func(this);
		}

		bool GetAllCollectorRayHitAt(uint32_t i, hknpCollisionResult& res)
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitAt);
			static REL::Relocation<func_t> func{ REL::ID(583997) };
			return func(this, i, res);
		}

		void SortAllCollectorHits()
		{
			using func_t = decltype(&bhkPickData::SortAllCollectorHits);
			static REL::Relocation<func_t> func{ REL::ID(1274842) };
			return func(this);
		}

		NiAVObject* GetNiAVObject()
		{
			using func_t = decltype(&bhkPickData::GetNiAVObject);
			static REL::Relocation<func_t> func{ REL::ID(863406) };
			return func(this);
		}

		hknpBody* GetBody()
		{
			using func_t = decltype(&bhkPickData::GetBody);
			static REL::Relocation<func_t> func{ REL::ID(1223055) };
			return func(this);
		}

		// members
		std::uint64_t        field_0;
		std::uint16_t        field_8;
		CFilter              collisionFilter;
		std::uint64_t        field_10;
		std::uint32_t        field_18;
		hkVector4f           rayOrigin;
		hkVector4f           rayDest;
		char                 gap40[16];
		int                  field_50;
		hknpCollisionResult  result;
		hknpCollisionResult* field_C0;
		std::uint64_t        collisionLayer;
		__int64              collector;
		int                  field_D8;
		__int16              field_DC;
		char                 field_DE;
		char                 field_DF;
	};
	static_assert(sizeof(bhkPickData) == 0xE0);
};
