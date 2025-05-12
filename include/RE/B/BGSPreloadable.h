#pragma once

namespace RE
{
	class __declspec(novtable) BGSPreloadable :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPreloadable };
		static constexpr auto VTABLE{ VTABLE::BGSPreloadable };

		// add
		virtual void QueueModelsImpl(void* a_queued, IO_TASK_PRIORITY, QueuedFile*, const TBO_InstanceData*) = 0;  // 07 - todo
	};
	static_assert(sizeof(BGSPreloadable) == 0x8);
}
