#pragma once

namespace RE
{
	class hknpViewerColorScheme
	{
	public:
		virtual ~hknpViewerColorScheme() = default;

		virtual std::uint32_t GetBodyColor(const hknpWorld&, hknpBodyId, hknpViewer*) = 0;
		virtual bool          IsBodyVisible(const hknpWorld&, hknpBodyId, hknpViewer*) = 0;
	};
	static_assert(sizeof(hknpViewerColorScheme) == 0x8);
}
