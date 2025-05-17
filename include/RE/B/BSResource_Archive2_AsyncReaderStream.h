#pragma once

#include "RE/B/BSResource_AsyncStream.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSFixedString.h"

namespace RE::BSResource
{
	namespace Archive2
	{
		class __declspec(novtable) AsyncReaderStream :
			public AsyncStream  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSResource__Archive2__AsyncReaderStream };
			static constexpr auto VTABLE{ VTABLE::BSResource__Archive2__AsyncReaderStream };

			AsyncReaderStream()
			{
				stl::emplace_vtable<AsyncReaderStream>(this);
			}

			// override
			ErrorCode DoOpen() override  // 01
			{
				using func_t = decltype(&AsyncReaderStream::DoOpen);
				static REL::Relocation<func_t> func{ REL::ID(1401160) };
				return func(this);
			}

			void DoClose() override  // 02
			{
				using func_t = decltype(&AsyncReaderStream::DoClose);
				static REL::Relocation<func_t> func{ REL::ID(883012) };
				return func(this);
			}

			void DoClone(BSTSmartPointer<AsyncStream>& a_result) const override  // 05
			{
				using func_t = decltype(&AsyncReaderStream::DoClone);
				static REL::Relocation<func_t> func{ REL::ID(803750) };
				return func(this, a_result);
			}

			ErrorCode DoStartRead(
				void*         a_buffer,
				std::uint64_t a_bytes,
				std::uint64_t a_offset) const override  // 06
			{
				using func_t = decltype(&AsyncReaderStream::DoStartRead);
				static REL::Relocation<func_t> func{ REL::ID(1215072) };
				return func(this, a_buffer, a_bytes, a_offset);
			}

			ErrorCode DoStartPacketAlignedBufferedRead(
				PacketAlignedBuffer* a_buffer,
				std::uint64_t        a_bytes,
				std::uint64_t        a_offset) const override  // 07
			{
				using func_t = decltype(&AsyncReaderStream::DoStartPacketAlignedBufferedRead);
				static REL::Relocation<func_t> func{ REL::ID(603387) };
				return func(this, a_buffer, a_bytes, a_offset);
			}

			ErrorCode DoStartWrite(const void*, std::uint64_t, std::uint64_t) const override  // 08
			{
				return ErrorCode::kUnsupported;
			}

			ErrorCode DoTruncate(std::uint64_t) const override  // 09
			{
				return ErrorCode::kUnsupported;
			}

			ErrorCode DoWait(std::uint64_t& a_transferred, bool a_block) override  // 0B
			{
				using func_t = decltype(&AsyncReaderStream::DoWait);
				static REL::Relocation<func_t> func{ REL::ID(2269399) };
				return func(this, a_transferred, a_block);
			}

			// members
			BSTSmartPointer<AsyncStream> source;                   // 18
			std::uint64_t                startOffset = 0;          // 20
			PacketAlignedBuffer*         currentBuffer = nullptr;  // 28
			BSFixedString                nameText;                 // 30
		};
		static_assert(sizeof(AsyncReaderStream) == 0x38);
	}
}
