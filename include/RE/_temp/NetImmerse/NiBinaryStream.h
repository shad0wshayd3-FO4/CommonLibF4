#pragma once

namespace RE
{
	class __declspec(novtable) NiBinaryStream
	{
	public:
		static constexpr auto RTTI{ RTTI::NiBinaryStream };
		static constexpr auto VTABLE{ VTABLE::NiBinaryStream };

		struct BufferInfo
		{
			void*       buffer;           // 00
			std::size_t fileSize;         // 08
			std::size_t bufferAllocSize;  // 10
			std::size_t bufferReadSize;   // 18
			std::size_t pos;              // 20
			std::size_t absCurrentPos;    // 28
		};
		static_assert(sizeof(BufferInfo) == 0x30);

		NiBinaryStream();
		virtual ~NiBinaryStream();  // 00

		// add
		virtual explicit    operator bool() const = 0;                               // 01
		virtual void        Seek(std::ptrdiff_t a_numBytes) = 0;                     // 02
		virtual std::size_t GetPosition() const { return absoluteCurrentPos; }       // 03
		virtual void        GetBufferInfo(BufferInfo& a_info);                       // 04
		virtual std::size_t DoRead(void* a_buffer, std::size_t a_bytes) = 0;         // 05
		virtual std::size_t DoWrite(const void* a_buffer, std::size_t a_bytes) = 0;  // 06

		template <class CharT>
		bool get(CharT& a_ch);
		template <class CharT>
		bool read(CharT* a_str, std::size_t a_count);
		template <class CharT>
		bool put(CharT a_ch);
		template <class CharT>
		bool write(const CharT* a_str, std::size_t a_count);

		std::size_t binary_read(void* a_buffer, std::size_t a_totalBytes);
		std::size_t binary_write(const void* a_buffer, std::size_t a_totalBytes);

		// members
		std::size_t absoluteCurrentPos;  // 08
	};
	static_assert(sizeof(NiBinaryStream) == 0x10);
	template <class CharT>
	inline bool NiBinaryStream::get(CharT& a_ch)
	{
		return read(&a_ch, 1);
	}

	template <class CharT>
	inline bool NiBinaryStream::read(CharT* a_str, std::size_t a_count)
	{
		std::size_t size = sizeof(CharT);
		std::size_t toRead = a_count * size;
		std::size_t bytesRead = binary_read(a_str, toRead);
		return bytesRead == toRead;
	}

	template <class CharT>
	inline bool NiBinaryStream::put(CharT a_ch)
	{
		return write(&a_ch, 1);
	}

	template <class CharT>
	inline bool NiBinaryStream::write(const CharT* a_str, std::size_t a_count)
	{
		std::size_t size = sizeof(CharT);
		std::size_t toWrite = a_count * size;
		std::size_t bytesWritten = binary_write(a_str, toWrite);
		return bytesWritten == toWrite;
	}
}
namespace std
{
	template <class CharT, class Traits, class Allocator>
	inline bool getline(RE::NiBinaryStream& a_input, std::basic_string<CharT, Traits, Allocator>& a_str)
	{
		CharT delim = std::use_facet<std::ctype<CharT>>(std::locale()).widen('\n');
		return getline(a_input, a_str, delim);
	}

	template <class CharT, class Traits, class Allocator>
	inline bool getline(RE::NiBinaryStream& a_input, std::basic_string<CharT, Traits, Allocator>& a_str, CharT a_delim)
	{
		a_str.erase();
		CharT c;
		auto  notEOF = a_input.get(c);
		if (notEOF) {
			do {
				if (!std::char_traits<CharT>::eq(c, a_delim)) {
					a_str.push_back(c);
				} else {
					break;
				}

				if (a_str.size() != a_str.max_size()) {
					notEOF = a_input.get(c);
				} else {
					break;
				}
			} while (notEOF);
			return true;
		} else {
			return false;
		}
	}
}
