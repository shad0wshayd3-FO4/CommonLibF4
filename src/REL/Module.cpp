#include "REL/Module.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	Module::Module()
	{
		const auto getFilename = [&]() {
			return REX::W32::GetEnvironmentVariableW(
				ENVIRONMENT.data(),
				_filename.data(),
				static_cast<std::uint32_t>(_filename.size()));
		};

		_filename.resize(getFilename());
		if (const auto result = getFilename();
			result != _filename.size() - 1 ||
			result == 0) {
			_filename = L"Fallout4.exe"sv;
		}

		auto handle = REX::W32::GetModuleHandleW(_filename.c_str());
		if (handle == nullptr) {
			stl::report_and_fail("failed to obtain module handle"sv);
		}

		_base = reinterpret_cast<std::uintptr_t>(handle);
		_natvis = _base;

		load_version();
		load_segments();
	}

	void Module::load_version()
	{
		const auto version = GetFileVersion(_filename);
		if (version) {
			_version = *version;
		} else {
			stl::report_and_fail("failed to obtain file version"sv);
		}
	}

	void Module::load_segments()
	{
		const auto dosHeader = reinterpret_cast<const REX::W32::IMAGE_DOS_HEADER*>(_base);
		const auto ntHeader = stl::adjust_pointer<REX::W32::IMAGE_NT_HEADERS64>(dosHeader, dosHeader->lfanew);
		const auto sections = REX::W32::IMAGE_FIRST_SECTION(ntHeader);
		const auto size = std::min<std::size_t>(ntHeader->fileHeader.sectionCount, _segments.size());
		for (std::size_t i = 0; i < size; ++i) {
			const auto& section = sections[i];
			const auto  it = std::find_if(SEGMENTS.begin(), SEGMENTS.end(), [&](auto&& a_elem) {
                constexpr auto size = std::extent_v<decltype(section.name)>;
                const auto     len = std::min(a_elem.size(), size);
                return std::memcmp(a_elem.data(), section.name, len) == 0;
            });
			if (it != SEGMENTS.end()) {
				const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
				_segments[idx] = Segment{ _base, _base + section.virtualAddress, section.virtualSize };
			}
		}
	}
}
