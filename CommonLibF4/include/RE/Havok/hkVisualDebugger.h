#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkReferencedObject.h"

namespace RE
{
	class hkClass;
	class hkProcessContext;
	class hkSocket;
	class hkStringPtr;
	class hkVisualDebuggerClient;
	class hkVisualDebuggerTrackedObject;
	class hkVtableClassRegistry;

	class hkVisualDebugger :
		public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hkVisualDebugger };
		inline static constexpr auto VTABLE{ VTABLE::hkVisualDebugger };

		using TrackCallback = void(*)(void*, const hkClass*, hkBool, std::uint64_t, void*);

		hkVisualDebugger(const hkArray<hkProcessContext*>& a_contexts, const hkVtableClassRegistry* a_classReg = nullptr)
		{
			using func_t = void(*)(hkVisualDebugger*, const hkArray<hkProcessContext*>&, const hkVtableClassRegistry*);
			static REL::Relocation<func_t> func{ REL::ID(2263295) };
			func(this, a_contexts, a_classReg);
		}

		virtual void Step(float a_frameTime)
		{
			using func_t = decltype(&hkVisualDebugger::Step);
			static REL::Relocation<func_t> func{ REL::ID(2263308) };
			func(this, a_frameTime);
		}

		virtual void PollForNewClients()
		{
			using func_t = decltype(&hkVisualDebugger::PollForNewClients);
			static REL::Relocation<func_t> func{ REL::ID(2263309) };
			func(this);
		}

		void AddContext(hkProcessContext* a_context)
		{
			using func_t = decltype(&hkVisualDebugger::AddContext);
			static REL::Relocation<func_t> func{ REL::ID(2263313) };
			func(this, a_context);
		}

		void AddDefaultProcess(const char* a_name)
		{
			using func_t = decltype(&hkVisualDebugger::AddDefaultProcess);
			static REL::Relocation<func_t> func{ REL::ID(2263302) };
			func(this, a_name);
		}

		void Serve(const std::uint32_t a_port = 25001)
		{
			using func_t = decltype(&hkVisualDebugger::Serve);
			static REL::Relocation<func_t> func{ REL::ID(2263296) };
			func(this, a_port);
		}

		void Shutdown()
		{
			using func_t = decltype(&hkVisualDebugger::Shutdown);
			static REL::Relocation<func_t> func{ REL::ID(2263300) };
			func(this);
		}

		// members
		hkSocket*                              server;                     // 10
		bool                                   suppressPollForNewClients;  // 18
		hkArray<hkVisualDebuggerClient>        clients;                    // 20
		hkArray<hkProcessContext*>             contexts;                   // 30
		hkArray<hkVisualDebuggerTrackedObject> trackedObjects;             // 40
		hkArray<TrackCallback>                 trackCallbacks;             // 50
		hkArray<void*>                         trackCallbackHandles;       // 60
		const hkVtableClassRegistry*           classReg;                   // 70
		hkArray<hkStringPtr>                   defaultProcesses;           // 78
		hkArray<hkStringPtr>                   requiredProcesses;          // 88
		hkBool                                 timingFrame;                // 98
		hkStopwatch                            frameTimer;                 // A0
		hkBool                                 overrideFrameTimeIfZero;    // D0
	};
	static_assert(sizeof(hkVisualDebugger) == 0xD8);
}
