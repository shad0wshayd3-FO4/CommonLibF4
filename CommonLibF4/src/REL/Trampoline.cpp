#include "REL/Trampoline.h"

#include "REL/ASM.h"
#include "REL/Utility.h"

#include "REX/W32/KERNEL32.h"

// xbyak brings in <Windows.h>
#ifdef F4SE_SUPPORT_XBYAK
#	include <xbyak/xbyak.h>
#   undef ERROR
#	undef max
#	undef MEM_COMMIT
#	undef MEM_FREE
#	undef MEM_RELEASE
#	undef MEM_RESERVE
#	undef PAGE_EXECUTE_READWRITE
#endif

namespace REL
{
	namespace Impl
	{
		constexpr std::size_t RoundUp(const std::size_t a_number, const std::size_t a_multiple) noexcept
		{
			if (a_multiple == 0)
				return 0;

			const auto remainder = a_number % a_multiple;
			return (remainder == 0) ? a_number : (a_number + a_multiple - remainder);
		}

		constexpr std::size_t RoundDown(const std::size_t a_number, const std::size_t a_multiple) noexcept
		{
			if (a_multiple == 0)
				return 0;

			const auto remainder = a_number % a_multiple;
			return (remainder == 0) ? a_number : (a_number - remainder);
		}

		// https://stackoverflow.com/a/54732489
		void* AllocTrampoline(const std::size_t a_size, const std::uintptr_t a_address)
		{
			constexpr std::size_t    gigabyte = static_cast<std::size_t>(1) << 30;
			constexpr std::size_t    minRange = gigabyte * 2;
			constexpr std::uintptr_t maxAddr = std::numeric_limits<std::uintptr_t>::max();

			REX::W32::SYSTEM_INFO si;
			REX::W32::GetSystemInfo(&si);
			const std::uint32_t granularity = si.allocationGranularity;

			std::uintptr_t       min = a_address >= minRange ? RoundUp(a_address - minRange, granularity) : 0;
			const std::uintptr_t max = a_address < (maxAddr - minRange) ? RoundDown(a_address + minRange, granularity) : maxAddr;

			REX::W32::MEMORY_BASIC_INFORMATION mbi;
			do {
				if (!REX::W32::VirtualQuery(reinterpret_cast<void*>(min), std::addressof(mbi), sizeof(mbi))) {
					REX::ERROR("VirtualQuery failed with code: 0x{:08X}"sv, REX::W32::GetLastError());
					return nullptr;
				}

				const auto baseAddr = reinterpret_cast<std::uintptr_t>(mbi.baseAddress);
				min = baseAddr + mbi.regionSize;

				if (mbi.state == REX::W32::MEM_FREE) {
					const std::uintptr_t addr = RoundUp(baseAddr, granularity);

					// if rounding didn't advance us into the next region and the region is the required size
					if (addr < min && (min - addr) >= a_size) {
						const auto mem = REX::W32::VirtualAlloc(
							reinterpret_cast<void*>(addr), a_size, REX::W32::MEM_COMMIT | REX::W32::MEM_RESERVE, REX::W32::PAGE_EXECUTE_READWRITE);
						if (mem) {
							return mem;
						}
						REX::ERROR("VirtualAlloc failed with code: 0x{:08X}"sv, REX::W32::GetLastError());
					}
				}
			} while (min < max);

			return nullptr;
		}
	}

	Trampoline::Trampoline(Trampoline&& a_rhs) noexcept
	{
		m_branch5 = std::move(a_rhs.m_branch5);
		m_branch6 = std::move(a_rhs.m_branch6);
		m_name = std::move(a_rhs.m_name);
		m_deleter = std::move(a_rhs.m_deleter);
		m_data = std::exchange(a_rhs.m_data, nullptr);
		m_capacity = std::exchange(a_rhs.m_capacity, 0);
		m_size = std::exchange(a_rhs.m_size, 0);
	}

	void Trampoline::create(const std::size_t a_size, void* a_module)
	{
		if (a_size == 0) {
			stl::report_and_fail("cannot create a trampoline with a zero size"sv);
		}

		if (!a_module) {
			const auto text = REL::Module::get().segment(REL::Segment::text);
			a_module = text.pointer<std::byte>() + text.size();
		}

		auto mem = Impl::AllocTrampoline(a_size, reinterpret_cast<std::uintptr_t>(a_module));
		if (!mem) {
			stl::report_and_fail("failed to create trampoline"sv);
		}

		set_trampoline(mem, a_size, [](void* a_mem, std::size_t) {
			REX::W32::VirtualFree(a_mem, 0, REX::W32::MEM_RELEASE);
		});
	}

	void Trampoline::set_trampoline(void* a_trampoline, const std::size_t a_size, deleter_type a_deleter)
	{
		auto trampoline = static_cast<std::byte*>(a_trampoline);
		if (trampoline) 
			std::memset(trampoline, REL::INT3, a_size);

		release();

		m_deleter = std::move(a_deleter);
		m_data = trampoline;
		m_capacity = a_size;
		m_size = 0;

		stats();
	}

	void* Trampoline::allocate(const std::size_t a_size)
	{
		if (a_size > free_size()) {
			stl::report_and_fail(std::format("Failed to handle allocation request\nAllocate Size: {}\nFree Size: {}", a_size, free_size()));
		}

		auto mem = m_data + m_size;
		m_size += a_size;

		stats();
		return mem;
	}

#ifdef F4SE_SUPPORT_XBYAK
	void* Trampoline::allocate(const Xbyak::CodeGenerator& a_code)
	{
		auto mem = allocate(a_code.getSize());
		std::memcpy(mem, a_code.getCode(), a_code.getSize());
		return mem;
	}
#endif

	std::uintptr_t Trampoline::write_call5(const std::uintptr_t a_src, const std::uintptr_t a_dst)
	{
		const auto original = ASM::CALL5::TARGET(a_src);
		ASM::CALL5 assembly(a_src, allocate_branch5(a_dst));
		REL::WriteSafeData(a_src, assembly);
		return original;
	}

	std::uintptr_t Trampoline::write_call6(const std::uintptr_t a_src, const std::uintptr_t a_dst)
	{
		const auto original = ASM::CALL6::TARGET(a_src);
		ASM::CALL6 assembly(a_src, allocate_branch6(a_dst));
		REL::WriteSafeData(a_src, assembly);
		return original;
	}

	std::uintptr_t Trampoline::write_jmp5(const std::uintptr_t a_src, const std::uintptr_t a_dst)
	{
		const auto original = ASM::JMP5::TARGET(a_src);
		ASM::JMP5  assembly(a_src, allocate_branch5(a_dst));
		REL::WriteSafeData(a_src, assembly);
		return original;
	}

	std::uintptr_t Trampoline::write_jmp6(const std::uintptr_t a_src, const std::uintptr_t a_dst)
	{
		const auto original = ASM::JMP6::TARGET(a_src);
		ASM::JMP6  assembly(a_src, allocate_branch6(a_dst));
		REL::WriteSafeData(a_src, assembly);
		return original;
	}

	std::uintptr_t Trampoline::allocate_branch5(const std::uintptr_t a_dst)
	{
		ASM::JMP14* mem = nullptr;
		if (const auto it = m_branch5.find(a_dst); it != m_branch5.end()) {
			mem = reinterpret_cast<ASM::JMP14*>(it->second);
			mem->addr = static_cast<std::uint64_t>(a_dst);
		} else {
			mem = allocate<ASM::JMP14>(a_dst);
			m_branch5.emplace(a_dst, reinterpret_cast<std::byte*>(mem));
		}

		return reinterpret_cast<std::uintptr_t>(mem);
	}

	std::uintptr_t Trampoline::allocate_branch6(const std::uintptr_t a_dst)
	{
		std::uintptr_t* mem = nullptr;
		if (const auto it = m_branch6.find(a_dst); it != m_branch6.end()) {
			mem = reinterpret_cast<std::uintptr_t*>(it->second);
			*mem = a_dst;
		} else {
			mem = allocate<std::uintptr_t>(a_dst);
			m_branch6.emplace(a_dst, reinterpret_cast<std::byte*>(mem));
		}

		return reinterpret_cast<std::uintptr_t>(mem);
	}

	void Trampoline::release()
	{
		if (m_data && m_deleter)
			m_deleter(m_data, m_capacity);

		m_branch5.clear();
		m_branch6.clear();
		m_data = nullptr;
		m_capacity = 0;
		m_size = 0;
	}

	void Trampoline::stats() const
	{
		auto pct = (static_cast<double>(m_size) / static_cast<double>(m_capacity)) * 100.0;
		REX::DEBUG("{} => {}B / {}B ({:05.2f}%)", m_name, m_size, m_capacity, pct);
	}

	Trampoline& GetTrampoline() noexcept
	{
		static Trampoline trampoline;
		return trampoline;
	}
}
