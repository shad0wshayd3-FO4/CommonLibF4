#pragma once

namespace RE
{
	[[nodiscard]] inline std::span<DEFAULT_OBJECT_DATA, 394> GetDefaultObjectData()
	{
		static REL::Relocation<DEFAULT_OBJECT_DATA(*)[394]> data{ REL::ID(838886) };
		return { *data };
	}
}
