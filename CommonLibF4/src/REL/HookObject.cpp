#pragma once

#include "REL/HookStore.h"

namespace REL
{
	HookObject::HookObject(const std::uintptr_t a_address) :
		m_address(a_address)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
		m_name = std::to_string(m_handle);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const char* a_name) :
		m_address(a_address), m_name(a_name)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const HOOK_TYPE a_type) :
		m_address(a_address), m_type(a_type)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
		m_name = std::to_string(m_handle);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const HOOK_TYPE a_type, const HOOK_STEP a_step) :
		m_address(a_address), m_type(a_type), m_step(a_step)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
		m_name = std::to_string(m_handle);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const HOOK_STEP a_step) :
		m_address(a_address), m_step(a_step)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
		m_name = std::to_string(m_handle);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const char* a_name, const HOOK_TYPE a_type) :
		m_address(a_address), m_name(a_name), m_type(a_type)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
	}

	HookObject::HookObject(const std::uintptr_t a_address, const char* a_name, const HOOK_TYPE a_type, const HOOK_STEP a_step) :
		m_address(a_address), m_name(a_name), m_type(a_type), m_step(a_step)
	{
		m_handle = HookStore::GetSingleton()->Add(this);
	}

	HookObject::~HookObject()
	{
		HookStore::GetSingleton()->Remove(m_handle);
	}

	bool HookObject::Init()
	{
		return true;
	}

	HOOK_HANDLE HookObject::GetHandle() const
	{
		return m_handle;
	}

	const char* HookObject::GetName() const
	{
		return m_name.c_str();
	}

	HOOK_TYPE HookObject::GetType() const
	{
		return m_type;
	}

	HOOK_STEP HookObject::GetStep() const
	{
		return m_step;
	}

	std::size_t HookObject::GetSize() const
	{
		return m_size;
	}

	std::size_t HookObject::GetSizeTrampoline() const
	{
		return m_sizeTrampoline;
	}

	bool HookObject::GetEnabled() const
	{
		return m_enabled;
	}
}
