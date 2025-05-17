#pragma once

#include "Scaleform/T/ThreadId.h"

namespace Scaleform::Render
{
	class HAL;
	class Renderer2D;
	class TextureManager;

	class Interfaces
	{
	public:
		// members
		TextureManager* textureManager;  // 00
		HAL*            hal;             // 08
		Renderer2D*     renderer2D;      // 10
		ThreadId        renderThreadID;  // 18
	};
	static_assert(sizeof(Interfaces) == 0x20);
}
