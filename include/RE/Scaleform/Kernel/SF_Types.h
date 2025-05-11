#pragma once

namespace RE::Scaleform
{
	template <class E, class U = std::underlying_type_t<E>>
	using Flags = REX::EnumSet<E, U>;
}
