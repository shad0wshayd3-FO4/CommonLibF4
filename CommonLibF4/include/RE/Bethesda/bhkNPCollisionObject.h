#pragma once

#include "RE/Havok/hknpBodyId.h"
#include "RE/Havok/hknpMotionPropertiesId.h"
#include "RE/NetImmerse/NiCollisionObject.h"
#include "RE/NetImmerse/NiExtraData.h"
#include "RE/NetImmerse/NiFlags.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class bhkPhysicsSystem;
	class bhkWorld;
	class hknpBody;
	class hknpShape;
	class hkTransformf;

	class CFilter
	{
	public:
		~CFilter() noexcept {}  // intentional

		// members
		std::uint32_t filter;  // 0
	};
	static_assert(sizeof(CFilter) == 0x4);

	class __declspec(novtable) bhkNPCollisionObjectBase :
		public NiCollisionObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectBase };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectBase };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObjectBase };

		// add
		virtual void LockMotionImpl() = 0;  // 2C

		// members
		NiTFlags<std::uint16_t, bhkNPCollisionObjectBase> flags;  // 18
	};
	static_assert(sizeof(bhkNPCollisionObjectBase) == 0x20);

	class __declspec(novtable) bhkNPCollisionObject :
		public bhkNPCollisionObjectBase  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObject };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObject };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObject };

		// add
		virtual void CreateInstance(bhkWorld& a_world);             // 2D
		virtual void AddToWorld(bhkWorld& a_world);                 // 2E
		virtual void RemoveFromWorld();                             // 2F
		virtual bool SetCollisionFilterInfo(CFilter a_filterInfo);  // 30

		void CopyMembers(bhkNPCollisionObject* a_dest, NiCloningProcess& a_cloningProcess)
		{
			using func_t = decltype(&bhkNPCollisionObject::CopyMembers);
			static REL::Relocation<func_t> func{ REL::ID(2277907) };
			func(this, a_dest, a_cloningProcess);
		}

		const hknpBody* GetBody()
		{
			using func_t = decltype(&bhkNPCollisionObject::GetBody);
			static REL::Relocation<func_t> func{ REL::ID(2277926) };
			return func(this);
		}

		hknpBodyId& GetBodyId(hknpBodyId& a_id)
		{
			using func_t = decltype(&bhkNPCollisionObject::GetBodyId);
			static REL::Relocation<func_t> func{ REL::ID(2277928) };
			return func(this, a_id);
		}

		bhkPhysicsSystem* GetPhysicsSystem()
		{
			return system.get();
		}

		/*hknpShape* GetShape()
		{
			using func_t = decltype(&bhkNPCollisionObject::GetShape);
			static REL::Relocation<func_t> func{ REL::ID(315427) };
			return func(this);
		}

		bool GetTransform(hkTransformf& a_transform)
		{
			using func_t = decltype(&bhkNPCollisionObject::GetTransform);
			static REL::Relocation<func_t> func{ REL::ID(1508189) };
			return func(this, a_transform);
		}*/

		void SetMotionType(hknpMotionPropertiesId::Preset a_type)
		{
			using func_t = decltype(&bhkNPCollisionObject::SetMotionType);
			static REL::Relocation<func_t> func{ REL::ID(2277913) };
			func(this, a_type);
		}

		/* bool SetTransform(hkTransformf& a_transform)
		{
			using func_t = decltype(&bhkNPCollisionObject::SetTransform);
			static REL::Relocation<func_t> func{ REL::ID(178085) };
			return func(this, a_transform);
		}*/

		static bhkNPCollisionObject* Getbhk(bhkWorld* a_world, hknpBodyId& a_bodyId)
		{
			using func_t = decltype(&bhkNPCollisionObject::Getbhk);
			static REL::Relocation<func_t> func{ REL::ID(2277919) };
			return func(a_world, a_bodyId);
		}

		// members
		NiPointer<bhkPhysicsSystem> system;         // 20
		std::uint32_t               systemBodyIdx;  // 28
	};
	static_assert(sizeof(bhkNPCollisionObject) == 0x30);

	class __declspec(novtable) bhkNPCollisionObjectUnlinked :
		public bhkNPCollisionObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectUnlinked };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectUnlinked };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObjectUnlinked };

		class LinkExtraData :
			public NiExtraData
		{
		public:
			inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectUnlinked__LinkExtraData };
			inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectUnlinked__LinkExtraData };

			// members
			BSTSet<NiPointer<bhkNPCollisionObjectUnlinked>> linkedCollisionObjSet;
		};
	};
	static_assert(sizeof(bhkNPCollisionObjectUnlinked) == 0x30);
}
