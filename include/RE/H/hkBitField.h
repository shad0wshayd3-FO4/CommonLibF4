#pragma once

#include "RE/H/hkArray.h"

namespace RE
{
	template <class T>
	class hkBitFieldStorage
	{
	public:
		// members
		T            words;    // 00
		std::int32_t numBits;  // ??
	};

	template <class T>
	class hkOffsetBitFieldStorage
	{
	public:
		// members
		T            words;   // 00
		std::int32_t offset;  // ??
	};

	template <class T>
	class hkBitFieldBase
	{
	public:
		// members
		T storage;  // 00
	};

	class hkBitField :
		public hkBitFieldBase<hkBitFieldStorage<hkArray<std::uint32_t>>>
	{
	public:
	};

	class hkBitFieldEx :
		public hkBitField
	{
	public:
	};

	class hkOffsetBitField :
		public hkBitFieldBase<hkOffsetBitFieldStorage<hkArray<std::uint32_t>>>
	{
	public:
	};

	class hkOffsetBitFieldLocal :
		public hkBitFieldBase<hkOffsetBitFieldStorage<hkLocalArray<std::uint32_t>>>
	{
	public:
	};
}
