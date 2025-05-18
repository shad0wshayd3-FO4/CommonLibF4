#pragma once

namespace RE
{
	class hkMemoryAllocator
	{
	public:
		class ExtendedInterface;
		class MemoryStatistics;

		// add
		virtual ~hkMemoryAllocator();                                                    // 00
		virtual void*              blockAlloc(std::int32_t);                             // 01
		virtual void               blockFree(void*, std::int32_t);                       // 02
		virtual void*              bufAlloc(std::int32_t*);                              // 03
		virtual void               bufFree(void*, std::int32_t);                         // 04
		virtual void*              bufRealloc(void*, std::int32_t, std::int32_t*);       // 05
		virtual void               blockAllocBatch(void**, std::int32_t, std::int32_t);  // 06
		virtual void               blockFreeBatch(void**, std::int32_t, std::int32_t);   // 07
		virtual void               getMemoryStatistics(MemoryStatistics*);               // 08
		virtual void               getAllocatedSize(const void*, std::int32_t);          // 09
		virtual std::int32_t       resetPeakMemoryStatistics();                          // 0A
		virtual ExtendedInterface* getExtendedInterface();                               // 0B
	};
	static_assert(sizeof(hkMemoryAllocator) == 0x08);
}
