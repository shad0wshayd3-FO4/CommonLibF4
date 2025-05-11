#pragma once

#include "RE/Bethesda/BSResource/StreamBase.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE::BSResource
{
	class __declspec(novtable) AsyncStream :
		public StreamBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSResource__AsyncStream };
		static constexpr auto VTABLE{ VTABLE::BSResource__AsyncStream };

		struct PacketAlignedBuffer
		{
		public:
			std::uint64_t resultOffset = 0;        // 00
			std::uint32_t bufferSize = 0;          // 08
			void*         packetBuffer = nullptr;  // 10
			std::uint32_t dataRequestSize = 0;     // 18
			std::uint32_t dataSize = 0;            // 1C
			void*         dataStart = nullptr;     // 20
		};
		static_assert(sizeof(PacketAlignedBuffer) == 0x28);

		// add
		virtual void      DoClone(BSTSmartPointer<AsyncStream>& a_result) const = 0;                                                                 // 05
		virtual ErrorCode DoStartRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_offset) const = 0;                                      // 06
		virtual ErrorCode DoStartPacketAlignedBufferedRead(PacketAlignedBuffer* a_buffer, std::uint64_t a_bytes, std::uint64_t a_offset) const = 0;  // 07
		virtual ErrorCode DoStartWrite(const void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_offset) const = 0;                               // 08
		virtual ErrorCode DoTruncate(std::uint64_t a_bytes) const = 0;                                                                               // 09
		virtual ErrorCode DoPrefetchAt(
			[[maybe_unused]] std::uint64_t a_bytes,
			[[maybe_unused]] std::uint64_t a_pos,
			[[maybe_unused]] std::uint32_t a_priority) const { return ErrorCode::kUnsupported; }  // 0A
		virtual ErrorCode DoWait(std::uint64_t& a_transferred, bool a_block) = 0;                 // 0B

		// members
		std::uint32_t minPacketSize = 0;  // 10
	};
	static_assert(sizeof(AsyncStream) == 0x18);
}
