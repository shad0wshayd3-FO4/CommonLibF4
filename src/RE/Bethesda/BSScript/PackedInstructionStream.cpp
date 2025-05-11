#include "RE/Bethesda/BSScript/PackedInstructionStream.h"

namespace RE
{
	namespace BSScript
	{
		namespace ByteCode
		{
			PackedInstructionStream::PackedInstructionStream() :
				numInstructionBits(0),
				jumpTargetBitCount(0),
				localVariableBitCount(0),
				memberVariableBitCount(0),
				instructions(nullptr)
			{}
			PackedInstructionStream::PackedInstructionStream(
				void*         a_instructions,
				std::uint32_t a_numInstrBits,
				std::uint16_t a_jumpTargetBitCount,
				std::int8_t   a_localVariableBitCount,
				std::int8_t   a_memberVariableBitCount) :
				numInstructionBits(a_numInstrBits),
				jumpTargetBitCount(a_jumpTargetBitCount),
				localVariableBitCount(a_localVariableBitCount),
				memberVariableBitCount(a_memberVariableBitCount),
				instructions(a_instructions)
			{}
		}
	}
}