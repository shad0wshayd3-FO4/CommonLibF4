#pragma once

namespace Scaleform
{
	class StatBag
	{
	public:
	};
	static_assert(std::is_empty_v<StatBag>);
}
