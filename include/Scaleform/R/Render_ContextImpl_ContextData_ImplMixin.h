#pragma once

namespace Scaleform::Render
{
	class LinearHeap;

	namespace ContextImpl
	{
		class EntryData;

		template <class C, class B>
		class ContextData_ImplMixin : public B
		{
		public:
			virtual EntryData* ConstructCopy(LinearHeap& heap) const;
			virtual void       CopyTo(void* pdest) const;
			virtual void       Destroy();
		};
	}
}
