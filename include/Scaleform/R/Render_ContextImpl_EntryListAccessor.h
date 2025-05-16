#pragma once

namespace Scaleform::Render::ContextImpl
{
	struct EntryListAccessor
	{
	public:
	};
	static_assert(std::is_empty_v<EntryListAccessor>);
}
