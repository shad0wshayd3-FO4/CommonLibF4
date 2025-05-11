#pragma once

#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE::BSResource
{
	class AsyncStream;
	class LocationTraverser;
	class Stream;

	class __declspec(novtable) Location
	{
	public:
		static constexpr auto RTTI{ RTTI::BSResource__Location };
		static constexpr auto VTABLE{ VTABLE::BSResource__Location };

		virtual ~Location() {}  // 00

		// add
		virtual ErrorCode DoMount() { return ErrorCode::kNone; }                                                                                                              // 01
		virtual void      DoUnmount() { return; }                                                                                                                             // 02
		virtual ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_result, Location*& a_location, bool a_writable, LocationTraverser* a_traverser) = 0;  // 03
		virtual ErrorCode DoCreateAsyncStream(
			[[maybe_unused]] const char*                   a_path,
			[[maybe_unused]] BSTSmartPointer<AsyncStream>& a_result,
			[[maybe_unused]] Location*&                    a_location,
			[[maybe_unused]] bool                          a_writable,
			[[maybe_unused]] LocationTraverser*            a_traverser) { return ErrorCode::kUnsupported; }       // 04
		virtual ErrorCode DoTraversePrefix(char const* a_prefix, LocationTraverser& a_traverser) = 0;  // 05
		virtual ErrorCode DoGetInfo(
			[[maybe_unused]] char const*        a_path,
			[[maybe_unused]] Info&              a_result,
			[[maybe_unused]] LocationTraverser* a_traverser) { return ErrorCode::kUnsupported; }  // 07
		virtual ErrorCode DoGetInfo(
			[[maybe_unused]] char const* a_path,
			[[maybe_unused]] Info&       a_result,
			[[maybe_unused]] Location*&  a_location) { return ErrorCode::kUnsupported; }  // 06
		virtual ErrorCode DoDelete(
			[[maybe_unused]] char const* a_path) { return ErrorCode::kUnsupported; }                 // 08
		[[nodiscard]] virtual char const*   DoGetName() const { return nullptr; }                    // 09
		[[nodiscard]] virtual std::uint32_t DoQBufferHint() const { return 0x10000; }                // 0A
		[[nodiscard]] virtual std::uint32_t DoGetMinimumAsyncPacketSize() const { return 0x10000; }  // 0B

		F4_HEAP_REDEFINE_NEW(Location);

		// members
		bool mounted;  // 08
	};
	static_assert(sizeof(Location) == 0x10);
}
