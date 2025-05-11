#pragma once

#include "REL/HookObject.h"

#include "REX/REX/Singleton.h"

namespace REL
{
	class HookStore :
		public REX::Singleton<HookStore>
	{
	public:
		HOOK_HANDLE Add(HookObject* a_hook);
		void        Remove(const HOOK_HANDLE a_handle);

		void Init();

		void Enable();
		void Enable(const HOOK_HANDLE a_handle);
		void Enable(const HOOK_TYPE a_type);
		void Enable(const HOOK_STEP a_phase);

		void Disable();
		void Disable(const HOOK_HANDLE a_handle);
		void Disable(const HOOK_TYPE a_type);

		std::size_t GetSizeTrampoline();

	private:
		std::map<HOOK_HANDLE, HookObject*> m_hooks;
		std::queue<HOOK_HANDLE>            m_hookQueue;
		std::uint32_t                      m_handleCount{ 0 };
	};
}
