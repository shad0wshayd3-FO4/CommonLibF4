#pragma once

#include "Scaleform/P/Ptr.h"
#include "Scaleform/R/Render_ContextImpl_Entry.h"
#include "Scaleform/R/Render_ContextImpl_EntryChange.h"
#include "Scaleform/R/Render_ContextImpl_EntryData.h"
#include "Scaleform/R/Render_ContextImpl_EntryTable.h"
#include "Scaleform/R/Render_ContextImpl_RTHandle.h"
#include "Scaleform/R/Render_ContextImpl_RenderNotify.h"
#include "Scaleform/T/ThreadId.h"

namespace Scaleform
{
	class Event;
	class MemoryHeap;

	namespace Render::ContextImpl
	{
		class ContextCaptureNotify;
		class ContextLock;
		class Snapshot;

		class Context
		{
		public:
			// members
			MemoryHeap*                heap;                      // 000
			ThreadId                   createThreadID;            // 008
			EntryTable                 table;                     // 010
			Ptr<ContextLock>           captureLock;               // 070
			List<ContextCaptureNotify> captureNotifyList;         // 078
			RenderNotify*              renderer;                  // 088
			bool                       multiThreadedUse;          // 090
			bool                       nextCaptureCalledInFrame;  // 091
			volatile bool              captureCalled;             // 092
			volatile bool              diChangesRequired;         // 093
			volatile bool              shutdownRequested;         // 094
			Event* volatile shutdownEvent;                        // 098
			RenderNotify::ContextNode  renderNode;                // 0A0
			List<RTHandle::HandleData> rtHandleList;              // 0B8
			Snapshot*                  snapshots[4];              // 0C8
			std::uint64_t              snapshotFrameIDs[4];       // 0E8
			std::uint64_t              finalizedFrameID;          // 108
		};
		static_assert(sizeof(Context) == 0x110);
	}
}
