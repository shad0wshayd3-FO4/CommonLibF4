#pragma once

#include "REL/Trampoline.h"

namespace F4SE
{
	using Trampoline = REL::Trampoline;

	// DEPRECATED
	[[nodiscard]] REL::Trampoline& GetTrampoline() noexcept
	{
		return REL::GetTrampoline();
	}
}
