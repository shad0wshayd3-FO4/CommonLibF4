#include "REL/Relocation.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	void safe_write(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		bool          success = REX::W32::VirtualProtect(
					 reinterpret_cast<void*>(a_dst), a_count, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success = REX::W32::VirtualProtect(
				reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success);
	}

	void safe_fill(std::uintptr_t a_dst, std::uint8_t a_value, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		bool          success = REX::W32::VirtualProtect(
					 reinterpret_cast<void*>(a_dst), a_count, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success) {
			std::fill_n(reinterpret_cast<std::uint8_t*>(a_dst), a_count, a_value);
			success = REX::W32::VirtualProtect(
				reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success);
	}
}

#ifdef F4SE_SUPPORT_XBYAK
#	include <xbyak/xbyak.h>

namespace REL
{
	struct write_func_impl : Xbyak::CodeGenerator
	{
		write_func_impl(std::uintptr_t a_dst)
		{
			Xbyak::Label dst;
			jmp(ptr[rip + dst]);
			L(dst);
			dq(a_dst);
		}
	};

	template <class T>
	void Relocation<T>::write_func(const std::size_t a_count, const std::uintptr_t a_dst) requires(std::same_as<value_type, std::uintptr_t>)
	{
		safe_fill(address(), INT3, a_count);
		auto patch = write_func_impl{ a_dst };
		patch.ready();
		assert(patch.getSize() <= a_count);
		safe_write(address(), std::span{ patch.getCode<const std::byte*>(), patch.getSize() });
	}

	template void Relocation<std::uintptr_t>::write_func(const std::size_t, const std::uintptr_t);
}
#endif
