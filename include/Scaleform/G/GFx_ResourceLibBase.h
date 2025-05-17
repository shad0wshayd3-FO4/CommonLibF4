#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class Resource;

	class __declspec(novtable) ResourceLibBase :
		public RefCountBase<ResourceLibBase, 2>  // 00
	{
	public:
		// add
		virtual void RemoveResourceOnRelease(Resource* a_res) = 0;  // 01
		virtual void PinResource(Resource* a_res) = 0;              // 02
		virtual void UnpinResource(Resource* a_res) = 0;            // 03
	};
	static_assert(sizeof(ResourceLibBase) == 0x10);
}
