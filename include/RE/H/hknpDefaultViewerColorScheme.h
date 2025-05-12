#pragma once

#include "RE/H/hknpViewerColorScheme.h"

namespace RE
{
	class hknpDefaultViewerColorScheme :
		public hknpViewerColorScheme
	{
	public:
		hknpDefaultViewerColorScheme() = default;

		virtual std::uint32_t GetBodyColor(const hknpWorld&, hknpBodyId, hknpViewer*) override
		{
			return staticBodyColor;  // TODO: Get color based on body flags
		}

		virtual bool IsBodyVisible(const hknpWorld&, hknpBodyId, hknpViewer*) override
		{
			return true;  // TODO: err...?
		}

		// members
		std::uint32_t staticBodyColor{ 0xFF999999 };     // 08
		std::uint32_t dynamicBodyColor{ 0xFFFFB300 };    // 0C
		std::uint32_t keyframedBodyColor{ 0xFF800080 };  // 10
		std::uint32_t triggerColor{ 0x4400FF00 };        // 14
		std::uint32_t dontCollideColor{ 0x66FFFF00 };    // 18
	};
	static_assert(sizeof(hknpDefaultViewerColorScheme) == 0x20);
}
