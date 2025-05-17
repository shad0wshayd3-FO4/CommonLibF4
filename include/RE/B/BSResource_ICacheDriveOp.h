#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE::BSResource
{
	class CacheDrive;

	class __declspec(novtable) ICacheDriveOp :
		public BSIntrusiveRefCounted
	{
	public:
		virtual ~ICacheDriveOp() = default;
		virtual void OnValid(CacheDrive& p_cache_drive) = 0;
		virtual void OnInit(CacheDrive& p_cache_drive) = 0;
		virtual void OnPacketWrite(CacheDrive& p_cache_drive, std::uint64_t a_v) = 0;
		virtual void OnComplete(CacheDrive& p_cache_drive) = 0;
		virtual void OnError(CacheDrive& p_cache_drive) = 0;

		// members
		std::uint32_t unk08;  // 08
	};
	static_assert(sizeof(ICacheDriveOp) == 0x10);
}
