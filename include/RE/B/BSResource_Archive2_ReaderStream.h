#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSResource_Stream.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE::BSResource
{
	namespace Archive2
	{
		class __declspec(novtable) ReaderStream :
			public Stream  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSResource__Archive2__ReaderStream };
			static constexpr auto VTABLE{ VTABLE::BSResource__Archive2__ReaderStream };

			class PlatformContext;
			class StandardContext;

			ReaderStream() { stl::emplace_vtable<ReaderStream>(this); }

			// override
			ErrorCode DoOpen() override  // 01
			{
				using func_t = decltype(&ReaderStream::DoOpen);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoOpen };
				return func(this);
			}

			void DoClose() override  // 02
			{
				using func_t = decltype(&ReaderStream::DoClose);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoClose };
				return func(this);
			}

			std::uint64_t DoGetKey() const override  // 03
			{
				using func_t = decltype(&ReaderStream::DoGetKey);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoGetKey };
				return func(this);
			}

			void DoClone(BSTSmartPointer<Stream>& a_result) const override  // 05
			{
				using func_t = decltype(&ReaderStream::DoClone);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoClone };
				return func(this, a_result);
			}

			ErrorCode DoRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t& a_read) const override  // 06
			{
				using func_t = decltype(&ReaderStream::DoRead);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoRead };
				return func(this, a_buffer, a_bytes, a_read);
			}

			ErrorCode DoWrite(const void*, std::uint64_t, std::uint64_t& a_write) const override  // 08
			{
				a_write = 0;
				return ErrorCode::kUnsupported;
			}

			ErrorCode DoSeek(std::int64_t a_offset, SeekMode a_whence, std::uint64_t& a_pos) const override  // 09
			{
				using func_t = decltype(&ReaderStream::DoSeek);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoSeek };
				return func(this, a_offset, a_whence, a_pos);
			}

			ErrorCode DoPrefetchAll(std::uint32_t a_priority) const override  // 0E
			{
				using func_t = decltype(&ReaderStream::DoPrefetchAll);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoPrefetchAll };
				return func(this, a_priority);
			}

			bool DoGetName(BSFixedString& a_result) const override  // 0F
			{
				a_result = this->name;
				return a_result.size() != 0;
			}

			ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_result) const override  // 10
			{
				using func_t = decltype(&ReaderStream::DoCreateAsync);
				static REL::Relocation<func_t> func{ RE::ID::BSResource_Archive2_ReaderStream::DoCreateAsync };
				return func(this, a_result);
			}

			bool DoGetIsFromArchive() const override { return true; }  // 13

			[[nodiscard]] bool IsCompressedStandard() const noexcept { return (this->flags & 0x100) != 0; }
			[[nodiscard]] bool IsCompressedPlatform() const noexcept { return (this->flags & 0x200) != 0; }
			[[nodiscard]] bool IsCompressed() const noexcept { return (this->flags & 0x300) != 0; }
			[[nodiscard]] bool CtxInFullRead() const noexcept { return (this->flags & 0x400) != 0; }
			[[nodiscard]] bool CtxInScrapHeap() const noexcept { return (this->flags & 0x800) != 0; }
			[[nodiscard]] bool CtxMultiplexed() const noexcept { return (this->flags & 0x1000) != 0; }
			[[nodiscard]] bool HasEmbeddedName() const noexcept { return (this->flags & 0x2000) != 0; }

			// members
			BSTSmartPointer<Stream> source;  // 10
			union
			{
				StandardContext* standardCtx = nullptr;
				PlatformContext* platformCtx;
			};  // 18
			const std::uint64_t startOffset = 0;            // 02
			BSFixedString       name;                       // 28
			std::uint32_t       currentRelativeOffset = 0;  // 30
			std::uint32_t       compressedSize = 0;         // 34
			std::uint32_t       uncompressedSize = 0;       // 38
			std::uint32_t       flags = 0;                  // 3C
		};
		static_assert(sizeof(ReaderStream) == 0x40);
	}
}
