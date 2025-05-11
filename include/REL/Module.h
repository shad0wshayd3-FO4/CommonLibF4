#pragma once

#include "REL/Segment.h"
#include "REL/Version.h"

namespace REL
{
	class Module
	{
	public:
		Module(const Module&) = delete;
		Module(Module&&) = delete;

		Module& operator=(const Module&) = delete;
		Module& operator=(Module&&) = delete;

		[[nodiscard]] static Module& get()
		{
			static Module singleton;
			return singleton;
		}

		[[nodiscard]] constexpr std::uintptr_t base() const noexcept { return _base; }
		[[nodiscard]] stl::zwstring            filename() const noexcept { return _filename; }
		[[nodiscard]] constexpr Segment        segment(Segment::Name a_segment) const noexcept { return _segments[a_segment]; }
		[[nodiscard]] constexpr Version        version() const noexcept { return _version; }

		[[nodiscard]] void* pointer() const noexcept { return reinterpret_cast<void*>(base()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		Module();
		~Module() noexcept = default;

		void load_segments();
		void load_version();

		static constexpr auto ENVIRONMENT = L"F4SE_RUNTIME"sv;

		static constexpr std::array SEGMENTS{
			".text"sv,
			".interpr"sv,
			".idata"sv,
			".rdata"sv,
			".data"sv,
			".pdata"sv,
			".tls"sv
		};

		static inline std::uintptr_t _natvis{ 0 };

		std::wstring                        _filename;
		std::array<Segment, Segment::total> _segments;
		Version                             _version;
		std::uintptr_t                      _base{ 0 };
	};
}
