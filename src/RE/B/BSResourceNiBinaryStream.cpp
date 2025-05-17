#include "RE/B/BSResourceNiBinaryStream.h"

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
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::Seek };
		return func(this, a_numBytes);
	}

	std::size_t BSResourceNiBinaryStream::DoRead(void* a_buf, std::size_t a_toRead)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoRead);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::DoRead };
		return func(this, a_buf, a_toRead);
	}

	std::size_t BSResourceNiBinaryStream::DoWrite(const void* a_buf, std::size_t a_toWrite)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoWrite);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::DoWrite };
		return func(this, a_buf, a_toWrite);
	}

	void BSResourceNiBinaryStream::GetBufferInfo([[maybe_unused]] BufferInfo& a_buf)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::GetBufferInfo);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::GetBufferInfo };
		return func(this, a_buf);
	}

	BSResourceNiBinaryStream* BSResourceNiBinaryStream::ctor(const char* a_name, bool a_writeable, BSResource::Location* a_optionalStart, bool a_fullReadHint)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::ctor);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::ctor };
		return func(this, a_name, a_writeable, a_optionalStart, a_fullReadHint);
	}

	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = decltype(&BSResourceNiBinaryStream::dtor);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::dtor };
		return func(this);
	}

	[[nodiscard]] BSResourceNiBinaryStream* BSResourceNiBinaryStream::BinaryStreamWithRescan(const char* a_fileName)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::BinaryStreamWithRescan);
		static REL::Relocation<func_t> func{ ID::BSResourceNiBinaryStream::BinaryStreamWithRescan };
		return func(a_fileName);
	}
}
