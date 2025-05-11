#pragma once

#include "RE/Bethesda/BSResource/AsyncStream.h"
#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSResource/Entry.h"
#include "RE/Bethesda/BSResource/GlobalLocations.h"
#include "RE/Bethesda/BSResource/GlobalPaths.h"
#include "RE/Bethesda/BSResource/Location.h"
#include "RE/Bethesda/BSResource/LooseFileStreamBase.h"
#include "RE/Bethesda/BSResource/Stream.h"
#include "RE/Bethesda/BSResource/StreamBase.h"

namespace RE::BSResource
{
	[[nodiscard]] ErrorCode GetOrCreateStream(const char* a_fileName, BSTSmartPointer<Stream>& a_result, bool a_writable = false, Location* a_optionalStart = nullptr);

	inline void RegisterLocation(Location* a_location, std::uint32_t a_priority)
	{
		using func_t = decltype(&RegisterLocation);
		static REL::Relocation<func_t> func{ REL::ID(918408) };
		return func(a_location, a_priority);
	}
}
