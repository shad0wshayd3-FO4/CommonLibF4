#pragma once

namespace RE
{
	class MemoryManager
	{
	public:
		struct AutoScrapBuffer
		{
		public:
			AutoScrapBuffer() { Ctor(); }
			~AutoScrapBuffer() { Dtor(); }

			[[nodiscard]] void* GetPtr() const noexcept { return ptr; }

			// members
			void* ptr{ nullptr };  // 0

		private:
			AutoScrapBuffer* Ctor()
			{
				using func_t = decltype(&AutoScrapBuffer::Ctor);
				static REL::Relocation<func_t> func{ REL::ID(2267865) };
				return func(this);
			}

			void Dtor()
			{
				using func_t = decltype(&AutoScrapBuffer::Dtor);
				static REL::Relocation<func_t> func{ REL::ID(2267867) };
				return func(this);
			}
		};
		static_assert(sizeof(AutoScrapBuffer) == 0x8);

		struct ThreadScrapHeap
		{
		public:
			// members
			ScrapHeap        heap;                                            // 00
			ThreadScrapHeap* next{ nullptr };                                 // 90
			std::uint32_t    owningThread{ REX::W32::GetCurrentThreadId() };  // 98
		};
		static_assert(sizeof(ThreadScrapHeap) == 0xA0);

		[[nodiscard]] static MemoryManager& GetSingleton()
		{
			using func_t = decltype(&MemoryManager::GetSingleton);
			const REL::Relocation<func_t> func{ REL::ID(2193197) };
			return func();
		}

		[[nodiscard]] void* Allocate(std::size_t a_size, std::uint32_t a_alignment, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Allocate);
			const REL::Relocation<func_t> func{ REL::ID(2267872) };
			return func(this, a_size, a_alignment, a_alignmentRequired);
		}

		void Deallocate(void* a_mem, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Deallocate);
			const REL::Relocation<func_t> func{ REL::ID(2267874) };
			return func(this, a_mem, a_alignmentRequired);
		}

		[[nodiscard]] ScrapHeap* GetThreadScrapHeap()
		{
			using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
			const REL::Relocation<func_t> func{ REL::ID(2267850) };
			return func(this);
		}

		[[nodiscard]] void* Reallocate(void* a_oldMem, std::size_t a_newSize, std::uint32_t a_alignment, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Reallocate);
			const REL::Relocation<func_t> func{ REL::ID(2267873) };
			return func(this, a_oldMem, a_newSize, a_alignment, a_alignmentRequired);
		}

		void RegisterMemoryManager()
		{
			using func_t = decltype(&MemoryManager::RegisterMemoryManager);
			const REL::Relocation<func_t> func{ REL::ID(2228356) };
			return func(this);
		}

		// members
		bool                    initialized{ false };                    // 000
		std::uint16_t           numHeaps{ 0 };                           // 002
		std::uint16_t           numPhysicalHeaps{ 0 };                   // 004
		IMemoryHeap**           heaps{ nullptr };                        // 008
		bool*                   allowOtherContextAllocs{ nullptr };      // 010
		IMemoryHeap*            heapsByContext[127]{ nullptr };          // 018
		ThreadScrapHeap*        threadScrapHeap{ nullptr };              // 410
		IMemoryHeap**           physicalHeaps{ nullptr };                // 418
		IMemoryHeap*            bigAllocHeap{ nullptr };                 // 420
		IMemoryHeap*            emergencyHeap{ nullptr };                // 428
		BSSmallBlockAllocator*  smallBlockAllocator{ nullptr };          // 430
		CompactingStore::Store* compactingStore{ nullptr };              // 438
		IMemoryHeap*            externalHavokAllocator{ nullptr };       // 440
		bool                    specialHeaps{ false };                   // 448
		bool                    allowPoolUse{ true };                    // 449
		std::uint32_t           sysAllocBytes{ 0 };                      // 44C
		std::uint32_t           mallocBytes{ 0 };                        // 450
		std::uint32_t           alignmentForPools{ 4 };                  // 454
		std::uint32_t           mainThreadMemoryProblemPassSignal{ 0 };  // 458
		std::size_t             failedAllocationSize{ 0 };               // 460
		std::uint32_t           numMemoryProblemPassesRun{ 0 };          // 468
		std::size_t             timeOfLastMemoryProblemPass{ 0 };        // 470
		IMemoryHeap*            defaultHeap{ nullptr };                  // 478
	};
	static_assert(sizeof(MemoryManager) == 0x480);

	[[nodiscard]] inline void* malloc(std::size_t a_size)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Allocate(a_size, 0, false);
	}

	template <class T>
	[[nodiscard]] T* malloc()
	{
		return static_cast<T*>(malloc(sizeof(T)));
	}

	[[nodiscard]] inline void* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Allocate(a_size, static_cast<std::uint32_t>(a_alignment), true);
	}

	template <class T>
	[[nodiscard]] T* aligned_alloc()
	{
		return static_cast<T*>(aligned_alloc(alignof(T), sizeof(T)));
	}

	[[nodiscard]] inline void* calloc(std::size_t a_num, std::size_t a_size)
	{
		const auto ret = malloc(a_num * a_size);
		if (ret) {
			std::memset(ret, 0, a_num * a_size);
		}
		return ret;
	}

	template <class T>
	[[nodiscard]] T* calloc(std::size_t a_num)
	{
		return static_cast<T*>(calloc(a_num, sizeof(T)));
	}

	[[nodiscard]] inline void* realloc(void* a_ptr, std::size_t a_newSize)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Reallocate(a_ptr, a_newSize, 0, false);
	}

	[[nodiscard]] inline void* aligned_realloc(void* a_ptr, std::size_t a_alignment, std::size_t a_newSize)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Reallocate(a_ptr, a_newSize, static_cast<std::uint32_t>(a_alignment), true);
	}

	inline void free(void* a_ptr)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Deallocate(a_ptr, false);
	}

	inline void aligned_free(void* a_ptr)
	{
		auto& mem = MemoryManager::GetSingleton();
		return mem.Deallocate(a_ptr, true);
	}
}

#define F4_HEAP_REDEFINE_HELPER(...)                                                                          \
	[[nodiscard]] void* operator new(std::size_t a_count, std::align_val_t a_alignment)                       \
	{                                                                                                         \
		const auto mem = RE::aligned_alloc(static_cast<std::size_t>(a_alignment), a_count);                   \
		if (mem) {                                                                                            \
			return mem;                                                                                       \
		} else {                                                                                              \
			RE::stl::report_and_fail("out of memory"sv);                                                      \
		}                                                                                                     \
	}                                                                                                         \
                                                                                                              \
	[[nodiscard]] void* operator new[](std::size_t a_count, std::align_val_t a_alignment)                     \
	{                                                                                                         \
		const auto mem = RE::aligned_alloc(static_cast<std::size_t>(a_alignment), a_count);                   \
		if (mem) {                                                                                            \
			return mem;                                                                                       \
		} else {                                                                                              \
			RE::stl::report_and_fail("out of memory"sv);                                                      \
		}                                                                                                     \
	}                                                                                                         \
                                                                                                              \
	[[nodiscard]] void* operator new(std::size_t, void* a_ptr) noexcept { return a_ptr; }                     \
	[[nodiscard]] void* operator new[](std::size_t, void* a_ptr) noexcept { return a_ptr; }                   \
	[[nodiscard]] void* operator new(std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; }   \
	[[nodiscard]] void* operator new[](std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; } \
                                                                                                              \
	void operator delete(void*, void*) noexcept { return; }                                                   \
	void operator delete[](void*, void*) noexcept { return; }                                                 \
                                                                                                              \
	void operator delete(void* a_ptr, std::align_val_t) { RE::aligned_free(a_ptr); }                          \
	void operator delete[](void* a_ptr, std::align_val_t) { RE::aligned_free(a_ptr); }                        \
	void operator delete(void* a_ptr, std::size_t, std::align_val_t) { RE::aligned_free(a_ptr); }             \
	void operator delete[](void* a_ptr, std::size_t, std::align_val_t) { RE::aligned_free(a_ptr); }

#define F4_HEAP_REDEFINE_NEW(...)                                         \
	[[nodiscard]] void* operator new(std::size_t a_count)                 \
	{                                                                     \
		const auto mem = RE::malloc(a_count);                             \
		if (mem) {                                                        \
			return mem;                                                   \
		} else {                                                          \
			RE::stl::report_and_fail("out of memory"sv);                  \
		}                                                                 \
	}                                                                     \
                                                                          \
	[[nodiscard]] void* operator new[](std::size_t a_count)               \
	{                                                                     \
		const auto mem = RE::malloc(a_count);                             \
		if (mem) {                                                        \
			return mem;                                                   \
		} else {                                                          \
			RE::stl::report_and_fail("out of memory"sv);                  \
		}                                                                 \
	}                                                                     \
                                                                          \
	void operator delete(void* a_ptr) { RE::free(a_ptr); }                \
	void operator delete[](void* a_ptr) { RE::free(a_ptr); }              \
	void operator delete(void* a_ptr, std::size_t) { RE::free(a_ptr); }   \
	void operator delete[](void* a_ptr, std::size_t) { RE::free(a_ptr); } \
                                                                          \
	F4_HEAP_REDEFINE_HELPER(__VA_ARGS__)

#define F4_HEAP_REDEFINE_ALIGNED_NEW(...)                                         \
	[[nodiscard]] void* operator new(std::size_t a_count)                         \
	{                                                                             \
		const auto mem = RE::aligned_alloc(alignof(__VA_ARGS__), a_count);        \
		if (mem) {                                                                \
			return mem;                                                           \
		} else {                                                                  \
			RE::stl::report_and_fail("out of memory"sv);                          \
		}                                                                         \
	}                                                                             \
                                                                                  \
	[[nodiscard]] void* operator new[](std::size_t a_count)                       \
	{                                                                             \
		const auto mem = RE::aligned_alloc(alignof(__VA_ARGS__), a_count);        \
		if (mem) {                                                                \
			return mem;                                                           \
		} else {                                                                  \
			RE::stl::report_and_fail("out of memory"sv);                          \
		}                                                                         \
	}                                                                             \
                                                                                  \
	void operator delete(void* a_ptr) { RE::aligned_free(a_ptr); }                \
	void operator delete[](void* a_ptr) { RE::aligned_free(a_ptr); }              \
	void operator delete(void* a_ptr, std::size_t) { RE::aligned_free(a_ptr); }   \
	void operator delete[](void* a_ptr, std::size_t) { RE::aligned_free(a_ptr); } \
                                                                                  \
	F4_HEAP_REDEFINE_HELPER(__VA_ARGS__)
