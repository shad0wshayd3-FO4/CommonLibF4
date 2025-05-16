#pragma once

#include "Scaleform/L/List.h"

namespace Scaleform::Render::ContextImpl
{
	class Context;
	class RenderNotify;

	class __declspec(novtable) ContextCaptureNotify :
		public ListNode<ContextCaptureNotify>  // 00
	{
	public:
		virtual ~ContextCaptureNotify();  // 00

		// add
		virtual void OnCapture() {}                                             // 01
		virtual void OnNextCapture([[maybe_unused]] RenderNotify* a_notify) {}  // 02
		virtual void OnShutdown([[maybe_unused]] bool a_waitFlag) {}            // 03

		// members
		Context* ownedContext{ nullptr };  // 18
	};
	static_assert(sizeof(ContextCaptureNotify) == 0x20);
}
