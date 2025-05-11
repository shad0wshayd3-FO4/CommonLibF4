#pragma once

#include "RE/Bethesda/Atomic.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSResource/StreamBase.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE::BSResource
{
	class AsyncStream;
	class CacheDrive;

	class __declspec(novtable) ICacheDriveOp :
		public BSIntrusiveRefCounted
	{
		virtual ~ICacheDriveOp() = default;
		virtual void OnValid(BSResource::CacheDrive& p_cache_drive) = 0;                           // 142D39FA0
		virtual void OnInit(BSResource::CacheDrive& p_cache_drive) = 0;                            // 142D39FA8
		virtual void OnPacketWrite(BSResource::CacheDrive& p_cache_drive, std::uint64_t a_v) = 0;  // 142D39FB0
		virtual void OnComplete(BSResource::CacheDrive& p_cache_drive) = 0;                        // 142D39FB8
		virtual void OnError(BSResource::CacheDrive& p_cache_drive) = 0;                           // 142D39FC0

		// members
		// align 4
		std::uint32_t unk08;  // 08
	};
	static_assert(sizeof(ICacheDriveOp) == 0x10);

	class __declspec(novtable) Stream :
		public StreamBase
	{
	public:
		inline static constexpr auto RTTI = { RTTI::BSResource__Stream };
		inline static constexpr auto VTABLE = { VTABLE::BSResource__Stream };

		Stream();
		Stream(const Stream& a_rhs);
		Stream(Stream&& a_rhs);
		Stream(std::uint32_t a_totalSize, bool writable);
		~Stream() override = default;  // 00

		virtual void      DoClone(BSTSmartPointer<Stream>& a_result) const = 0;                                                                                                                                                                                     // 05
		virtual ErrorCode DoRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t& a_read) const = 0;                                                                                                                                                           // 06
		virtual ErrorCode DoReadAt(void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_pos, std::uint64_t& a_read) const;                                                                                                                                        // 07
		virtual ErrorCode DoWrite(const void* a_buffer, std::uint64_t a_bytes, std::uint64_t& a_write) const = 0;                                                                                                                                                   // 08
		virtual ErrorCode DoSeek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& a_pos) const = 0;                                                                                                                                                       // 09
		virtual ErrorCode DoSetEndOfStream();                                                                                                                                                                                                                       // 0A
		virtual ErrorCode DoPrefetchAt(std::uint64_t a_bytes, std::uint64_t a_offset, std::uint32_t a_priority) const;                                                                                                                                              // 0B
		virtual ErrorCode DoStartTaggedPrioritizedRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_offset, std::uint32_t a_priority, volatile std::uint32_t* a_completionTag, std::uint32_t& a_completionTagWaitValue, BSEventFlag* a_eventFlag) const;  // 0C

		virtual ErrorCode DoWaitTags(volatile std::uint32_t* a_completionTag, std::uint32_t a_completionTagWaitValue, BSEventFlag* a_eventFlag) const;  // 0D
		virtual ErrorCode DoPrefetchAll(std::uint32_t a_priority) const;                                                                                // 0E
		virtual bool      DoGetName(BSFixedString& a_result) const;                                                                                     // 0F
		virtual ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_result) const;                                                                  // 10
		virtual bool      DoQTaggedPrioritizedReadSupported() const;                                                                                    // 11
		virtual ErrorCode DoCreateOp(BSTSmartPointer<ICacheDriveOp>& a_result, char const* a_arg2) const;                                               // 12
		virtual bool      DoGetIsFromArchive() const;                                                                                                   // 13

		// non virtuals
		bool          GetName(BSFixedString& a_dst) const;                                                                                                                                             //0000000140004410
		ErrorCode     Open(bool buffered, bool fullReadHint);                                                                                                                                          //000000014012A830
		ErrorCode     Read(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const;                                                                                                       // 14012B2E0
		ErrorCode     Seek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const;                                                                                                    //00000001401B8160
		ErrorCode     Write(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const;                                                                                            //00000001402D6200
		ErrorCode     ReadAt(void* a_buffer, std::uint64_t a_offset, std::uint64_t a_toRead, std::uint64_t& a_read) const;                                                                             //000000014036DF60
		ErrorCode     CreateOp(BSTSmartPointer<ICacheDriveOp>& a_opOut, const char* name) const;                                                                                                       //0000000140D0F080
		ErrorCode     CreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const;                                                                                                                    //0000000141AF97F0
		ErrorCode     PrefetchAll(std::uint32_t a_v) const;                                                                                                                                            //0000000141B6EE50
		ErrorCode     PrefetchAt(std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_v) const;                                                                                                       // 141B7A0A0
		std::uint32_t QFullReadHint() const;                                                                                                                                                           // 141B7A5B0
		bool          QTaggedPrioritizedReadSupported() const;                                                                                                                                         // 141B7A780
		ErrorCode     StartTaggedPrioritizedRead(void* buf, std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_V, std::uint32_t volatile* d_v, std::uint32_t& e_v, BSEventFlag* event_flag) const;  // 141B7BB30
		ErrorCode     WaitTags(std::uint32_t volatile* a_v, std::uint32_t b_v, BSEventFlag* event_flag) const;                                                                                         // 141B7CAB0
		std::uint32_t QBuffered() const;                                                                                                                                                               // 141B87490
		ErrorCode     SetEndOfStream();                                                                                                                                                                // 141B8C9F0
	};
	static_assert(sizeof(Stream) == 0x10);
}
