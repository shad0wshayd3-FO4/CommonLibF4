#include "REL/Utility.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	void Write(void* a_dst, const void* a_src, const std::size_t a_size)
	{
		std::memcpy(a_dst, a_src, a_size);
	}

	void Write(const std::uintptr_t a_dst, const void* a_src, const std::size_t a_size)
	{
		std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_size);
	}

	void WriteSafe(void* a_dst, const void* a_src, const std::size_t a_size)
	{
		std::uint32_t protect{ 0 };

		bool success = REX::W32::VirtualProtect(a_dst, a_size, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(protect));
		if (success) {
			std::memcpy(a_dst, a_src, a_size);
			success = REX::W32::VirtualProtect(a_dst, a_size, protect, std::addressof(protect));
		}

		assert(success);
	}

	void WriteSafe(const std::uintptr_t a_dst, const void* a_src, const std::size_t a_size)
	{
		WriteSafe(reinterpret_cast<void*>(a_dst), a_src, a_size);
	}

	void WriteSafeFill(void* a_dst, const std::byte a_value, const std::size_t a_size)
	{
		std::uint32_t protect{ 0 };

		bool success = REX::W32::VirtualProtect(a_dst, a_size, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(protect));
		if (success) {
			std::fill_n(reinterpret_cast<std::byte*>(a_dst), a_size, a_value);
			success = REX::W32::VirtualProtect(a_dst, a_size, protect, std::addressof(protect));
		}

		assert(success);
	}

	void WriteSafeFill(const std::uintptr_t a_dst, const std::byte a_value, const std::size_t a_size)
	{
		WriteSafeFill(reinterpret_cast<void*>(a_dst), a_value, a_size);
	}
}
