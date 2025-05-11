#include "RE/Bethesda/BSResourceNiBinaryStream.h"

namespace RE
{
	BSResourceNiBinaryStream::BSResourceNiBinaryStream() :
		NiBinaryStream(),
		stream(nullptr),
		buffer(nullptr),
		pos(0),
		lastError(BSResource::ErrorCode::kNone)
	{}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_fileName) :
		NiBinaryStream(),
		stream(0),
		buffer(nullptr),
		pos(0),
		lastError(BSResource::ErrorCode::kNone)
	{
		ctor(a_fileName);
	}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const std::string& a_fileName) :
		BSResourceNiBinaryStream(a_fileName.c_str())
	{}

	BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
	{
		dtor();
	}
	void BSResourceNiBinaryStream::Seek(std::ptrdiff_t a_numBytes)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::Seek);
		REL::Relocation<func_t> func{ REL::ID(358512) };  // rel id ?141B93B30
		return func(this, a_numBytes);
	}

	std::size_t BSResourceNiBinaryStream::DoRead(void* a_buf, std::size_t a_toRead)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoRead);
		REL::Relocation<func_t> func{ REL::ID(424286) };  // rel id ?141B93D00
		return func(this, a_buf, a_toRead);
	}

	std::size_t BSResourceNiBinaryStream::DoWrite(const void* a_buf, std::size_t a_toWrite)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoWrite);
		REL::Relocation<func_t> func{ REL::ID(1208863) };  // rel id ?141B93D90
		return func(this, a_buf, a_toWrite);
	}

	void BSResourceNiBinaryStream::GetBufferInfo([[maybe_unused]] BufferInfo& a_buf)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::GetBufferInfo);
		REL::Relocation<func_t> func{ REL::ID(265501) };  // rel id ?141B93BA0
		return func(this, a_buf);
	}

	BSResourceNiBinaryStream* BSResourceNiBinaryStream::ctor(const char* a_name, bool a_writeable, BSResource::Location* a_optionalStart, bool a_fullReadHint)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::ctor);
		REL::Relocation<func_t> func{ REL::ID(1198116) };  //1B93740
		return func(this, a_name, a_writeable, a_optionalStart, a_fullReadHint);
	}

	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = decltype(&BSResourceNiBinaryStream::dtor);
		REL::Relocation<func_t> func{ REL::ID(1516202) };  //1B93A00
		return func(this);
	}

	[[nodiscard]] BSResourceNiBinaryStream* BSResourceNiBinaryStream::BinaryStreamWithRescan(const char* a_fileName)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::BinaryStreamWithRescan);
		REL::Relocation<func_t> func{ REL::ID(543595) };
		return func(a_fileName);
	}
}
