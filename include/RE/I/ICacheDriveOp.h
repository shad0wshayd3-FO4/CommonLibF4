#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	namespace BSResource
	{
		class __declspec(novtable) ICacheDriveOp :
			public BSIntrusiveRefCounted
		{
		public:
			virtual ~ICacheDriveOp() = default;
			virtual void OnValid(BSResource::CacheDrive& p_cache_drive) = 0;
			virtual void OnInit(BSResource::CacheDrive& p_cache_drive) = 0;
			virtual void OnPacketWrite(BSResource::CacheDrive& p_cache_drive, std::uint64_t a_v) = 0;
			virtual void OnComplete(BSResource::CacheDrive& p_cache_drive) = 0;
			virtual void OnError(BSResource::CacheDrive& p_cache_drive) = 0;

			// members
			// align 4
			std::uint32_t unk08;  // 08
		};
		static_assert(sizeof(ICacheDriveOp) == 0x10);
	}
}
