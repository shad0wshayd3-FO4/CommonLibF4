#pragma once

#include "RE/S/SFTypes.h"
#include "RE/S/SFRenderColor.h"
#include "RE/S/SFRenderMatrix2x4.h"
#include "RE/S/SFRenderMatrix3x4.h"
#include "RE/S/SFRenderMatrix4x4.h"
#include "RE/S/SFRenderTypes2D.h"

namespace RE::Scaleform::GFx
{
	using Render::Color;
	using Render::Matrix2F;
	using Render::Matrix3F;
	using Render::Matrix4F;
	using Render::Point;
	using Render::PointF;
	using Render::Rect;
	using Render::RectF;

	enum class PlayState
	{
		kPlaying,
		kStopped
	};

	enum class FocusMovedType
	{
		kByMouse = 1,
		kByKeyboard,
		kByAS
	};
}
