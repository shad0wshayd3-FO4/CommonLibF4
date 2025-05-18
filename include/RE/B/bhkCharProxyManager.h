#pragma once

#include "RE/B/bhkIWorldStepListener.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class bhkCharProxyController;

    class __declspec(novtable) bhkCharProxyManager :
		public bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharProxyManager };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharProxyManager };

		class ThreadLocalCharRBDeferredCmds;

		virtual ~bhkCharProxyManager();

		// members
		BSTArray<bhkCharProxyController*>                  proxyControllersA;
		BSTHashMap<bhkCharProxyController*, std::uint32_t> proxyControllerIndex;
		BSTArray<ThreadLocalCharRBDeferredCmds>            deferredCommandsA;
	};
	static_assert(sizeof(bhkCharProxyManager) == 0x70);
}
