#pragma once

#ifdef F4SE_SUPPORT_XBYAK
namespace Xbyak
{
	class CodeGenerator;
}
#endif

namespace REL
{
	class Trampoline
	{
	public:
		using deleter_type = std::function<void(void* a_mem, std::size_t a_size)>;

		Trampoline() noexcept = default;
		Trampoline(const Trampoline&) = delete;

		Trampoline(Trampoline&& a_rhs) noexcept;

		Trampoline(const std::string_view a_name) :
			m_name(a_name)
		{}

		~Trampoline() noexcept
		{
			release();
		}

		Trampoline& operator=(const Trampoline&) = delete;

		Trampoline& operator=(Trampoline&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				m_branch5 = std::move(a_rhs.m_branch5);
				m_branch6 = std::move(a_rhs.m_branch6);
				m_name = std::move(a_rhs.m_name);
				m_deleter = std::move(a_rhs.m_deleter);
				m_data = std::exchange(a_rhs.m_data, nullptr);
				m_capacity = std::exchange(a_rhs.m_capacity, 0);
				m_size = std::exchange(a_rhs.m_size, 0);
			}

			return *this;
		}

	public:
		void create(const std::size_t a_size, void* a_module = nullptr);

		void set_trampoline(void* a_trampoline, const std::size_t a_size, deleter_type a_deleter = {});

		[[nodiscard]] void* allocate(const std::size_t a_size);

#ifdef F4SE_SUPPORT_XBYAK
		[[nodiscard]] void* allocate(const Xbyak::CodeGenerator& a_code);
#endif

		template <class T, class... Args>
		[[nodiscard]] T* allocate(Args&&... a_args)
		{
			auto mem = allocate(sizeof(T));
			return new (mem) T(std::forward<Args>(a_args)...);
		}

		[[nodiscard]] constexpr std::size_t empty() const noexcept { return m_capacity == 0; }
		[[nodiscard]] constexpr std::size_t capacity() const noexcept { return m_capacity; }
		[[nodiscard]] constexpr std::size_t allocated_size() const noexcept { return m_size; }
		[[nodiscard]] constexpr std::size_t free_size() const noexcept { return m_capacity - m_size; }

		template <std::size_t N>
		std::uintptr_t write_call(const std::uintptr_t a_src, const std::uintptr_t a_dst)
		{
			if constexpr (N == 5)
				return write_call5(a_src, a_dst);
			else if constexpr (N == 6)
				return write_call6(a_src, a_dst);
			else
				static_assert(false && N, "invalid call size");
		}

		template <std::size_t N, class F>
		std::uintptr_t write_call(const std::uintptr_t a_src, F a_dst)
		{
			return write_call<N>(a_src, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

		template <std::size_t N>
		std::uintptr_t write_jmp(const std::uintptr_t a_src, const std::uintptr_t a_dst)
		{
			if constexpr (N == 5)
				return write_jmp5(a_src, a_dst);
			else if constexpr (N == 6)
				return write_jmp6(a_src, a_dst);
			else
				static_assert(false && N, "invalid jmp size");
		}

		template <std::size_t N, class F>
		std::uintptr_t write_jmp(const std::uintptr_t a_src, F a_dst)
		{
			return write_jmp<N>(a_src, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

		std::uintptr_t write_call5(const std::uintptr_t a_src, const std::uintptr_t a_dst);
		std::uintptr_t write_call6(const std::uintptr_t a_src, const std::uintptr_t a_dst);
		std::uintptr_t write_jmp5(const std::uintptr_t a_src, const std::uintptr_t a_dst);
		std::uintptr_t write_jmp6(const std::uintptr_t a_src, const std::uintptr_t a_dst);

		std::uintptr_t allocate_branch5(const std::uintptr_t a_dst);
		std::uintptr_t allocate_branch6(const std::uintptr_t a_dst);

	public:
		// DEPRECATED
		template <std::size_t N>
		std::uintptr_t write_branch(std::uintptr_t a_src, std::uintptr_t a_dst)
		{
			return write_jmp<N>(a_src, a_dst);
		}

		// DEPRECATED
		template <std::size_t N, class F>
		std::uintptr_t write_branch(std::uintptr_t a_src, F a_dst)
		{
			return write_jmp<N>(a_src, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

	private:
		void release();
		void stats() const;

	private:
		std::map<std::uintptr_t, std::byte*> m_branch5;
		std::map<std::uintptr_t, std::byte*> m_branch6;
		std::string                          m_name{ "Default Trampoline"sv };
		deleter_type                         m_deleter;
		std::byte*                           m_data{ nullptr };
		std::size_t                          m_capacity{ 0 };
		std::size_t                          m_size{ 0 };
	};

	[[nodiscard]] Trampoline& GetTrampoline() noexcept;
}
