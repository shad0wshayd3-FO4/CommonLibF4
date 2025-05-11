#include "RE/NetImmerse/NiBinaryStream.h"

namespace RE
{
	NiBinaryStream::NiBinaryStream() :
		absoluteCurrentPos(0)
	{}

	NiBinaryStream::~NiBinaryStream()
	{}

	void NiBinaryStream::GetBufferInfo(BufferInfo& a_buf)
	{
		a_buf.buffer = nullptr;
		a_buf.pos = 0;
		a_buf.bufferAllocSize = 0;
		a_buf.fileSize = 0;
		a_buf.bufferReadSize = 0;
		a_buf.absCurrentPos = 0;
	}

	std::size_t NiBinaryStream::binary_read(void* a_buffer, std::size_t a_totalBytes)
	{
		std::size_t bytesRead = DoRead(a_buffer, a_totalBytes);
		absoluteCurrentPos += bytesRead;
		return bytesRead;
	}

	std::size_t NiBinaryStream::binary_write(const void* a_buffer, std::size_t a_totalBytes)
	{
		std::size_t bytesWritten = DoWrite(a_buffer, a_totalBytes);
		absoluteCurrentPos += bytesWritten;
		return bytesWritten;
	}
}
