#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/bhkCharProxyManager.h"
#include "RE/B/bhkCharRigidBodyManager.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkVector4f.h"
#include "RE/H/hknpWorld.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class bhkTrapListener;
	class hclBSWorld;
	class hkbnpPhysicsInterface;
	class hknpBSWorld;
	class hknpPhysicsSystem;
	class hkTaskQueue;
	class NiAVObject;

	class __declspec(novtable) bhkWorld :
		public NiObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkWorld };
		inline static constexpr auto VTABLE{ VTABLE::bhkWorld };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkWorld };

		virtual ~bhkWorld();  // 00

		// add
		virtual bool Update(std::uint32_t a_updateFlags);  // 28
		virtual void Init(const hknpWorldCinfo& a_info);   // 29

		void AddPhysicsSystem(hknpPhysicsSystem* a_physicsSystem, bool a_startActive)
		{
			using func_t = decltype(&bhkWorld::AddPhysicsSystem);
			static REL::Relocation<func_t> func{ ID::bhkWorld::AddPhysicsSystem };
			func(this, a_physicsSystem, a_startActive);
		}

		void RemovePhysicsSystem(hknpPhysicsSystem* a_physicsSystem)
		{
			using func_t = decltype(&bhkWorld::RemovePhysicsSystem);
			static REL::Relocation<func_t> func{ ID::bhkWorld::RemovePhysicsSystem };
			func(this, a_physicsSystem);
		}

		inline static bool RemoveObjects(NiAVObject* a_object, bool a_recurse, bool a_force)
		{
			using func_t = decltype(&bhkWorld::RemoveObjects);
			static REL::Relocation<func_t> func{ ID::bhkWorld::RemoveObjects };
			return func(a_object, a_recurse, a_force);
		}

		// members
		hkRefPtr<hkTaskQueue>            taskQueue;
		BSTArray<bhkIWorldStepListener*> stepListenerA;
		hkRefPtr<hkbnpPhysicsInterface>  behaviorInterface;
		BSReadWriteLock                  charProxyManagerLock;
		BSReadWriteLock                  charRigidBodyManagerLock;
		BSReadWriteLock                  stepListenerALock;
		hkVector4f                       origin;
		hkRefPtr<hknpBSWorld>            worldNP;
		bhkCharProxyManager              charProxyManager;
		bhkCharRigidBodyManager          charRigidBodyManager;
		hkRefPtr<hclBSWorld>             clothWorld;
		char*                            clothStepBuffer;
		std::int32_t                     clothStepBufferSize;
		hknpWorld::AdditionMode          additionMode;
		bhkTrapListener*                 trapListener;
		float                            originalTau;
		float                            originalDamping;
		bool                             globalWindActivated;
		bool                             added;
		bool                             enabled;
	};
	static_assert(sizeof(bhkWorld) == 0x180);
}
