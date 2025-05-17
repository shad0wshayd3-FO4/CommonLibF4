#pragma once

namespace Scaleform::Render
{
	class Interfaces;
	class ThreadCommand;

	class __declspec(novtable) ThreadCommandQueue
	{
	public:
		virtual ~ThreadCommandQueue() = default;  // 00

		// add
		virtual void PushThreadCommand(ThreadCommand* a_command) = 0;  // 01
		virtual void GetRenderInterfaces(Interfaces* a_ptr);           // 02
	};
	static_assert(sizeof(ThreadCommandQueue) == 0x8);
}
