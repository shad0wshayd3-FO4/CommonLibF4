#pragma once

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IVMDebugInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IVMDebugInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IVMDebugInterface };

			virtual ~IVMDebugInterface();  // 00

			virtual void DumpRunningStacksToLog() = 0;                                                                                // 01   // 14307DA18
			virtual void DumpStackFrameToLog(unsigned int a_v, unsigned int b_v, bool a_flag) = 0;                                    // 02   // 14307DA20
			virtual void GetStackFrame(unsigned int a_v, unsigned int b_v, bool a_flag, BSFixedString& a_identifier) = 0;             // 03   // 14307DA28
			virtual void DumpPersistenceInformationToLog(char const* logfile, uint64_t a_v) const = 0;                                // 04   // 14307DA30
			virtual void DumpEventRelayInformationToLog(char const* logfile, uint64_t a_v, BSFixedString const& a_string) const = 0;  // 05   // 14307DA38
		};
		static_assert(sizeof(IVMDebugInterface) == 0x8);
	}
}
