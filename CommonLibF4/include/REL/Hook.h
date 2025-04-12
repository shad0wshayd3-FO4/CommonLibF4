#pragma once

#include "REL/ASM.h"
#include "REL/HookObject.h"
#include "REL/ID.h"
#include "REL/Trampoline.h"
#include "REL/Utility.h"

namespace REL
{
	template <class>
	class Hook;

	template <class R, class... T>
	class Hook<R(T...)> :
		public HookObject
	{
	public:
		explicit Hook(const ID a_id, const std::ptrdiff_t a_offset, R (*a_function)(T...)) :
			HookObject(a_id.address() + a_offset)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			Detect();
		}

		explicit Hook(const HOOK_STEP a_step, const ID a_id, const std::ptrdiff_t a_offset, R (*a_function)(T...)) :
			HookObject(a_id.address() + a_offset, a_step)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			Detect();
		}

		explicit Hook(const char* a_name, const ID a_id, const std::ptrdiff_t a_offset, R (*a_function)(T...)) :
			HookObject(a_id.address() + a_offset, a_name)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			Detect();
		}

		explicit Hook(const char* a_name, const HOOK_STEP a_step, const ID a_id, const std::ptrdiff_t a_offset, R (*a_function)(T...)) :
			HookObject(a_id.address() + a_offset, a_name, a_step)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			Detect();
		}

		virtual bool Init() override
		{
			if (m_type == HOOK_TYPE::NONE) {
				REX::ERROR("{}: could not determine hook type", *this);
				return false;
			}

			REL::Write(std::span{ m_bytesOld }, m_address);

			switch (m_type) {
				case HOOK_TYPE::CALL5: {
					ASM::CALL5 assembly(m_address, GetTrampoline().allocate_branch5(m_function));
					REL::WriteData(std::span{ m_bytes }, assembly);
				} break;
				case HOOK_TYPE::CALL6: {
					ASM::CALL6 assembly(m_address, GetTrampoline().allocate_branch6(m_function));
					REL::WriteData(std::span{ m_bytes }, assembly);
				} break;
				case HOOK_TYPE::JMP5: {
					ASM::JMP5 assembly(m_address, GetTrampoline().allocate_branch5(m_function));
					REL::WriteData(std::span{ m_bytes }, assembly);
				} break;
				case HOOK_TYPE::JMP6: {
					ASM::JMP6 assembly(m_address, GetTrampoline().allocate_branch6(m_function));
					REL::WriteData(std::span{ m_bytes }, assembly);
				} break;
			}

			return true;
		}

		virtual bool Enable() override
		{
			if (m_type == HOOK_TYPE::NONE) {
				REX::ERROR("{}: hook type is none", *this);
				return false;
			}

			REL::WriteSafe(m_address, std::span{ m_bytes });

			m_enabled = true;

			return true;
		}

		virtual bool Disable() override
		{
			if (m_type == HOOK_TYPE::NONE) {
				REX::ERROR("{}: hook type is none", *this);
				return false;
			}

			REL::WriteSafe(m_address, std::span{ m_bytesOld });

			m_enabled = false;

			return false;
		}

		R operator()(T... a_args) const
		{
			assert(m_functionOld);
			return std::invoke(reinterpret_cast<std::decay_t<R(T...)>>(m_functionOld), a_args...);
		}

	private:
		void Detect()
		{
			const auto op = reinterpret_cast<std::uint8_t*>(m_address);
			switch (*op) {
				case 0xE8: {
					m_type = HOOK_TYPE::CALL5;
					m_size = sizeof(ASM::CALL5);
					m_sizeTrampoline = sizeof(ASM::JMP14);
					m_functionOld = ASM::CALL5::TARGET(m_address);
				} break;
				case 0xE9: {
					m_type = HOOK_TYPE::JMP5;
					m_size = sizeof(ASM::JMP5);
					m_sizeTrampoline = sizeof(ASM::JMP14);
					m_functionOld = ASM::JMP5::TARGET(m_address);
				} break;
				case 0xFF: {
					switch (*(op + 1)) {
						case 0x15: {
							m_type = HOOK_TYPE::CALL6;
							m_size = sizeof(ASM::CALL6);
							m_sizeTrampoline = sizeof(std::uintptr_t);
							m_functionOld = ASM::CALL6::TARGET(m_address);
						} break;
						case 0x25: {
							m_type = HOOK_TYPE::JMP6;
							m_size = sizeof(ASM::JMP6);
							m_sizeTrampoline = sizeof(std::uintptr_t);
							m_functionOld = ASM::JMP6::TARGET(m_address);
						} break;
					}
				} break;
			}

			m_bytes.resize(m_size);
			m_bytesOld.resize(m_size);
		}

	private:
		std::uintptr_t m_function;
		std::uintptr_t m_functionOld;

		std::vector<std::byte> m_bytes;
		std::vector<std::byte> m_bytesOld;
	};

	template <class R, class... T>
	Hook(const ID, const std::uint64_t, R (*)(T...)) -> Hook<R(T...)>;

	template <class R, class... T>
	Hook(const HOOK_STEP, const ID, const std::uint64_t, R (*)(T...)) -> Hook<R(T...)>;

	template <class R, class... T>
	Hook(const char*, const ID, const std::uint64_t, R (*)(T...)) -> Hook<R(T...)>;

	template <class R, class... T>
	Hook(const char*, const HOOK_STEP, const ID, const std::uint64_t, R (*)(T...)) -> Hook<R(T...)>;
}

namespace REL
{
	template <class>
	class HookVFT;

	template <class R, class... T>
	class HookVFT<R(T...)> :
		public HookObject
	{
	public:
		explicit HookVFT(const ID a_id, const std::size_t a_idx, R (*a_function)(T...)) :
			HookObject(a_id.address() + (sizeof(void*) * a_idx), HOOK_TYPE::VFT)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			m_functionOld = *reinterpret_cast<std::uintptr_t*>(m_address);
		}

		explicit HookVFT(const HOOK_STEP a_step, const ID a_id, const std::size_t a_idx, R (*a_function)(T...)) :
			HookObject(a_id.address() + (sizeof(void*) * a_idx), HOOK_TYPE::VFT, a_step)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			m_functionOld = *reinterpret_cast<std::uintptr_t*>(m_address);
		}

		explicit HookVFT(const char* a_name, const ID a_id, const std::size_t a_idx, R (*a_function)(T...)) :
			HookObject(a_id.address() + (sizeof(void*) * a_idx), a_name, HOOK_TYPE::VFT)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			m_functionOld = *reinterpret_cast<std::uintptr_t*>(m_address);
		}

		explicit HookVFT(const char* a_name, const HOOK_STEP a_step, const ID a_id, const std::size_t a_idx, R (*a_function)(T...)) :
			HookObject(a_id.address() + (sizeof(void*) * a_idx), a_name, HOOK_TYPE::VFT, a_step)
		{
			m_function = reinterpret_cast<std::uintptr_t>(a_function);
			m_functionOld = *reinterpret_cast<std::uintptr_t*>(m_address);
		}

		virtual bool Enable() override
		{
			if (!m_address) {
				REX::ERROR("{}: address is null", *this);
				return false;
			}

			REL::WriteSafeData(m_address, m_function);

			m_enabled = true;

			return true;
		}

		virtual bool Disable() override
		{
			if (!m_address) {
				REX::ERROR("{}: address is null", *this);
				return false;
			}

			REL::WriteSafeData(m_address, m_functionOld);

			m_enabled = false;

			return true;
		}

		R operator()(T... a_args) const
		{
			assert(m_functionOld);
			return std::invoke(reinterpret_cast<std::decay_t<R(T...)>>(m_functionOld), a_args...);
		}

	private:
		std::uintptr_t m_function;
		std::uintptr_t m_functionOld;
	};

	template <class R, class... T>
	HookVFT(const ID, const std::size_t, R (*)(T...)) -> HookVFT<R(T...)>;

	template <class R, class... T>
	HookVFT(const HOOK_STEP, const ID, const std::size_t, R (*)(T...)) -> HookVFT<R(T...)>;

	template <class R, class... T>
	HookVFT(const char*, const ID, const std::size_t, R (*)(T...)) -> HookVFT<R(T...)>;

	template <class R, class... T>
	HookVFT(const char*, const HOOK_STEP, const ID, const std::size_t, R (*)(T...)) -> HookVFT<R(T...)>;
}
