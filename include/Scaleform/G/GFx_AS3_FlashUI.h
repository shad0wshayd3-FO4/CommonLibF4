#pragma once

namespace Scaleform::GFx::AS3
{
	class __declspec(novtable) FlashUI
	{
	public:
		enum class OutputMessageType : std::int32_t
		{
			kMessage,
			kError,
			kWarning,
			kAction
		};

		enum class StateType : std::int32_t
		{
			kError,
			kBreakpoint,
			kPreStep,
			kStep
		};

		virtual ~FlashUI();  // 00

		// add
		virtual void Output(OutputMessageType a_type, const char* a_msg) = 0;  // 01
		virtual bool OnOpCode(std::uint64_t a_opCode) = 0;                     // 02

		// members
		StateType state;        // 08
		bool      needToCheck;  // 0C
	};
	static_assert(sizeof(FlashUI) == 0x10);
}
