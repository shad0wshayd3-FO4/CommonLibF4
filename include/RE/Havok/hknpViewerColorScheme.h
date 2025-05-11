#pragma once

#include "RE/Havok/hknpBodyId.h"

namespace RE
{
	class hknpWorld;
	class hknpViewer;

	class hknpViewerColorScheme
	{
	public:
		virtual ~hknpViewerColorScheme() = default;

		virtual std::uint32_t GetBodyColor(const hknpWorld&, hknpBodyId, hknpViewer*) = 0;
		virtual bool          IsBodyVisible(const hknpWorld&, hknpBodyId, hknpViewer*) = 0;
	};
	static_assert(sizeof(hknpViewerColorScheme) == 0x8);
}
