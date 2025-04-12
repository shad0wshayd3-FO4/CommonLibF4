#pragma once

#pragma pack(push, 1)

namespace REL::ASM
{
	template <std::uint8_t OP>
	struct BRANCH5
	{
		explicit constexpr BRANCH5(const std::int32_t a_disp) :
			disp(a_disp)
		{}

		explicit constexpr BRANCH5(const std::uintptr_t a_address, const std::uintptr_t a_fn) :
			disp(static_cast<std::int32_t>(a_fn - (a_address + sizeof(BRANCH5))))
		{}

		static std::uintptr_t TARGET(const std::uintptr_t a_address)
		{
			const auto branch = reinterpret_cast<BRANCH5*>(a_address);
			const auto begin = reinterpret_cast<std::uint8_t*>(a_address);
			const auto address = (begin + sizeof(BRANCH5)) + branch->disp;
			return reinterpret_cast<std::uintptr_t>(address);
		}

		std::uint8_t op{ OP };  // 0
		std::int32_t disp;      // 1
	};

	using CALL5 = BRANCH5<0xE8>;
	static_assert(sizeof(CALL5) == 0x5);

	using JMP5 = BRANCH5<0xE9>;
	static_assert(sizeof(JMP5) == 0x5);

	template <std::uint8_t RM>
	struct BRANCH6
	{
		explicit constexpr BRANCH6(const std::int32_t a_disp) :
			disp(a_disp)
		{}

		explicit constexpr BRANCH6(const std::uintptr_t a_address, const std::uintptr_t a_fn) :
			disp(static_cast<std::int32_t>(a_fn - (a_address + sizeof(BRANCH6))))
		{}

		static std::uintptr_t TARGET(const std::uintptr_t a_address)
		{
			const auto branch = reinterpret_cast<BRANCH6*>(a_address);
			const auto begin = reinterpret_cast<std::uint8_t*>(a_address);
			const auto address = (begin + sizeof(BRANCH6)) + branch->disp;
			return reinterpret_cast<std::uintptr_t>(address);
		}

		std::uint8_t op{ 0xFF };  // 0
		std::uint8_t rm{ RM };    // 1
		std::int32_t disp;        // 2
	};

	using CALL6 = BRANCH6<0x15>;
	static_assert(sizeof(CALL6) == 0x6);

	using JMP6 = BRANCH6<0x25>;
	static_assert(sizeof(JMP6) == 0x6);

	struct CALL16
	{
		explicit constexpr CALL16(const std::uintptr_t a_addr) :
			addr(a_addr)
		{}

		template <class T>
		explicit constexpr CALL16(const T* a_fn) :
			CALL16(reinterpret_cast<std::uintptr_t>(a_fn))
		{}

		CALL6         call{ 0x2 };  // 0 - 0x2
		std::uint8_t  op{ 0xEB };   // 6 - 0xEB
		std::int8_t   disp{ 0x8 };  // 7 - 0x8
		std::uint64_t addr;         // 8
	};
	static_assert(sizeof(CALL16) == 0x10);

	struct JMP14
	{
		explicit constexpr JMP14(const std::uintptr_t a_addr) :
			addr(a_addr)
		{}

		template <class T>
		explicit constexpr JMP14(const T* a_fn) :
			JMP14(reinterpret_cast<std::uintptr_t>(a_fn))
		{}

		JMP6          jmp{ 0x0 };  // 0 - 0x0
		std::uint64_t addr;        // 6 - [rip]
	};
	static_assert(sizeof(JMP14) == 0xE);
}

#pragma pack(pop)
