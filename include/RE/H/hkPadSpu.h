#pragma once

namespace RE
{
	template <class T>
	class hkPadSpu
	{
	public:
		~hkPadSpu() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		T storage;
	};

}
