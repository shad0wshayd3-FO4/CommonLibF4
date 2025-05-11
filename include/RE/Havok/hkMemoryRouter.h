#pragma once

#include "RE/Havok/hkLifoAllocator.h"

namespace RE
{
	class hkMemoryAllocator;

	class hkMemoryRouter
	{
	public:
		using Allocator = hkMemoryAllocator;
		using Stack = hkLifoAllocator;

		[[nodiscard]] static hkMemoryRouter& GetInstance()
		{
			return *GetInstancePtr();
		}

		[[nodiscard]] static hkMemoryRouter* GetInstancePtr()
		{
			static REL::Relocation<std::uint32_t*> slot{ REL::ID(878080) };
			return static_cast<hkMemoryRouter*>(REX::W32::TlsGetValue(*slot));
		}

		static void ReplaceInstance(hkMemoryRouter* a_router)
		{
			static REL::Relocation<std::uint32_t*> slot{ REL::ID(878080) };
			REX::W32::TlsSetValue(*slot, a_router);
		}

		void                 SetDebug(Allocator* a_val) noexcept { debug = a_val; }
		void                 SetHeap(Allocator* a_val) noexcept { heap = a_val; }
		void                 SetSolver(Allocator* a_val) noexcept { solver = a_val; }
		void                 SetTemp(Allocator* a_val) noexcept { temp = a_val; }
		[[nodiscard]] Stack& GetStack() noexcept { return stack; }

		// members
		Stack              stack;                  // 00
		hkMemoryAllocator* temp{ nullptr };        // 50
		hkMemoryAllocator* heap{ nullptr };        // 58
		hkMemoryAllocator* debug{ nullptr };       // 60
		hkMemoryAllocator* solver{ nullptr };      // 68
		void*              userData{ nullptr };    // 70
		std::uint32_t      refObjLocalStore{ 0 };  // 78
	};
	static_assert(sizeof(hkMemoryRouter) == 0x80);
}
