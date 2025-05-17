#pragma once

#include "Scaleform/L/List.h"
#include "Scaleform/R/Render_PagedItemBuffer.h"
#include "Scaleform/R/Render_ThreadCommand.h"

namespace Scaleform::Render::ContextImpl
{
	class Context;
	class Entry;
	class EntryChange;
	class ThreadCommandQueue;

	class __declspec(novtable) RenderNotify
	{
	public:
		class ContextNode :
			public ListNode<ContextNode>  // 00
		{
		public:
			// members
			Context* context;  // 10
		};
		static_assert(sizeof(ContextNode) == 0x18);

		class __declspec(novtable) ServiceCommand :
			public ThreadCommand  // 00
		{
		public:
			void Execute() override;  // 01

			// members
			RenderNotify* notify;  // 10
		};
		static_assert(sizeof(ServiceCommand) == 0x18);

		virtual ~RenderNotify();

		virtual void NewCapture(Context* a_context, bool a_hasChanges);
		virtual void ContextReleased(Context* a_context);
		virtual void ServiceQueues();
		virtual void EntryChanges(Context&, PagedItemBuffer<EntryChange, 63>&, [[maybe_unused]] bool a_forceUpdateImages = false) {}
		virtual void EntryDestroy(Entry*) {}
		virtual void EntryFlush(Entry*) {}

		// members
		List<ContextNode>   activeContextSet;        // 08
		ThreadCommandQueue* rtCommandQueue;          // 18
		ServiceCommand      serviceCommandInstance;  // 20
	};
	static_assert(sizeof(RenderNotify) == 0x38);
}
