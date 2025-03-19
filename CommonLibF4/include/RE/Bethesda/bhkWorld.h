#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Havok/hkRefPtr.h"
#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpWorld.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class bhkCharProxyController;
	class bhkCharRigidBodyController;
	class bhkNPCollisionObject;
	class bhkTrapListener;
	class hclBSWorld;
	class hkbnpPhysicsInterface;
	class hknpBSWorld;
	class hknpPhysicsSystem;
	class hknpWorldCinfo;
	class hkTaskQueue;
	class NiAVObject;

	class __declspec(novtable) bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkIWorldStepListener };
		inline static constexpr auto VTABLE{ VTABLE::bhkIWorldStepListener };

		virtual ~bhkIWorldStepListener();

		// members
		BSTArray<BSTArray<NiPointer<bhkNPCollisionObject>>>* deferredReleaseColObjs;
	};
	static_assert(sizeof(bhkIWorldStepListener) == 0x10);

	class __declspec(novtable) bhkCharProxyManager :
		public bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharProxyManager };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharProxyManager };

		struct ThreadLocalCharRBDeferredCmds;

		virtual ~bhkCharProxyManager();

		// members
		BSTArray<bhkCharProxyController*>                  proxyControllersA;
		BSTHashMap<bhkCharProxyController*, std::uint32_t> proxyControllerIndex;
		BSTArray<ThreadLocalCharRBDeferredCmds>            deferredCommandsA;
	};
	static_assert(sizeof(bhkCharProxyManager) == 0x70);

	class __declspec(novtable) bhkCharRigidBodyManager :
		public bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharRigidBodyManager };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharRigidBodyManager };

		struct ThreadLocalCharRBDeferredCmds;

		virtual ~bhkCharRigidBodyManager();

		// members
		BSTArray<bhkCharRigidBodyController*>                  rigidBodyControllersA;
		BSTHashMap<bhkCharRigidBodyController*, std::uint32_t> rigidBodyControllerIndex;
		BSTArray<ThreadLocalCharRBDeferredCmds>                deferredCommandsA;
	};
	static_assert(sizeof(bhkCharRigidBodyManager) == 0x70);

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
			static REL::Relocation<func_t> func{ REL::ID(2277752) };
			func(this, a_physicsSystem, a_startActive);
		}

		void RemovePhysicsSystem(hknpPhysicsSystem* a_physicsSystem)
		{
			using func_t = decltype(&bhkWorld::RemovePhysicsSystem);
			static REL::Relocation<func_t> func{ REL::ID(2277753) };
			func(this, a_physicsSystem);
		}

		inline static bool RemoveObjects(NiAVObject* a_object, bool a_recurse, bool a_force)
		{
			using func_t = decltype(&bhkWorld::RemoveObjects);
			static REL::Relocation<func_t> func{ REL::ID(2277721) };
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

	class __declspec(novtable) bhkWorldM :
		public bhkWorld  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkWorldM };
		inline static constexpr auto VTABLE{ VTABLE::bhkWorldM };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkWorldM };

		virtual ~bhkWorldM();  // 00

		// members
		hkVector4f worldTotalSize;
		hkVector4f borderSize;
		hkVector4f broadPhaseSize;
	};
	static_assert(sizeof(bhkWorldM) == 0x1B0);
}
