#pragma once

#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSResource/Stream.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/NetImmerse/NiBinaryStream.h"

namespace RE
{
	namespace BSResource
	{
		class Location;
	}

	class BSResourceNiBinaryStream : public NiBinaryStream
	{
	public:
		inline static constexpr auto RTTI = { RTTI::BSResourceNiBinaryStream };
		inline static constexpr auto VTABLE = { VTABLE::BSResourceNiBinaryStream };

		struct BufferType
		{
		public:
			// BSResource::Stream &stream; //00
			// std::uint64_t unk10;
			// std::uint64_t unk18;
			// std::uint32_t unk20;
			// std::uint32_t gap24;
			// std::uint64_t unk28;
			// std::uint32_t unk30;
		};

		BSResourceNiBinaryStream();
		BSResourceNiBinaryStream(const char* a_fileName);
		BSResourceNiBinaryStream(const std::string& a_fileName);
		~BSResourceNiBinaryStream() override;  // 00

		// override (NiBinaryStream)
		explicit    operator bool() const noexcept override { return static_cast<bool>(stream); };  // 01 - { return static_cast<bool>(stream); }
		void        Seek(std::ptrdiff_t a_numBytes) override;                                       // 02
		std::size_t GetPosition() const noexcept override { return pos; };                          // 03 - { return streamPos; }
		void        GetBufferInfo(BufferInfo& a_buf) override;                                      // 04
		std::size_t DoRead(void* a_buf, std::size_t a_toRead) override;                             // 05
		std::size_t DoWrite(const void* a_buf, std::size_t a_toWrite) override;                     // 05

		bool good() { return static_cast<bool>(stream); };

		[[nodiscard]] static BSResourceNiBinaryStream* BinaryStreamWithRescan(const char* a_fileName);

		// members
		BSTSmartPointer<BSResource::Stream> stream;     // 10
		BufferType*                         buffer;     // 18
		std::size_t                         pos;        // 20
		BSResource::ErrorCode               lastError;  // 28

	private:
		BSResourceNiBinaryStream* ctor(const char* a_name, bool a_writeable = false, BSResource::Location* a_optionalStart = 0, bool a_fullReadHint = false);
		void                      dtor();
	};

	static_assert(sizeof(BSResourceNiBinaryStream) == 0x30);
}
