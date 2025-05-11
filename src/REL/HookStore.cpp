#include "REL/HookStore.h"

#include "REL/Hook.h"

namespace REL
{
	HOOK_HANDLE HookStore::Add(HookObject* a_hook)
	{
		if (a_hook && a_hook->GetHandle() == 0) {
			m_hooks.insert({ ++m_handleCount, a_hook });
			m_hookQueue.push(m_handleCount);
			return m_handleCount;
		}

		return 0;
	}

	void HookStore::Remove(const HOOK_HANDLE a_handle)
	{
		m_hooks.erase(a_handle);
	}

	void HookStore::Init()
	{
		REX::DEBUG("Init {} queued hooks", m_hookQueue.size());
		while (!m_hookQueue.empty()) {
			m_hooks[m_hookQueue.front()]->Init();
			m_hookQueue.pop();
		}
	}

	void HookStore::Enable()
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook) {
				hook->Enable();
			}
		}
	}

	void HookStore::Enable(const HOOK_HANDLE a_handle)
	{
		if (const auto it = m_hooks.find(a_handle); it != m_hooks.end()) {
			if (it->second) {
				it->second->Enable();
			}
		}
	}

	void HookStore::Enable(const HOOK_TYPE a_type)
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook && hook->GetType() == a_type) {
				hook->Enable();
			}
		}
	}

	void HookStore::Enable(const HOOK_STEP a_phase)
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook && hook->GetStep() == a_phase) {
				hook->Enable();
			}
		}
	}

	void HookStore::Disable()
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook) {
				hook->Disable();
			}
		}
	}

	void HookStore::Disable(const HOOK_HANDLE a_handle)
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook && hook->GetHandle() == a_handle) {
				hook->Disable();
			}
		}
	}

	void HookStore::Disable(const HOOK_TYPE a_type)
	{
		for (auto& [name, hook] : m_hooks) {
			if (hook && hook->GetType() == a_type) {
				hook->Disable();
			}
		}
	}

	std::size_t HookStore::GetSizeTrampoline()
	{
		std::size_t size{ 0 };
		for (auto& [name, hook] : m_hooks) {
			if (hook) {
				size += hook->GetSizeTrampoline();
			}
		}

		return size;
	}
}
