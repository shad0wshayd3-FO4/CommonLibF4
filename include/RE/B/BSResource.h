#pragma once

#include "RE/B/BSResource_ErrorCode.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE::BSResource
{
	class Location;
	class Stream;

	[[nodiscard]] ErrorCode GetOrCreateStream(const char* a_fileName, BSTSmartPointer<Stream>& a_result, bool a_writable = false, Location* a_optionalStart = nullptr);

	inline void RegisterLocation(Location* a_location, std::uint32_t a_priority)
	{
		using func_t = decltype(&RegisterLocation);
		static REL::Relocation<func_t> func{ REL::ID(918408) };
		return func(a_location, a_priority);
	}
}
