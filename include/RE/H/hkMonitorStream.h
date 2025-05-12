#pragma once

namespace RE
{
	class hkMonitorStream
	{
	public:
		inline static hkMonitorStream* GetSingleton()
		{
			static REL::Relocation<std::uint32_t*> slot{ REL::ID(2702743) };
			return static_cast<hkMonitorStream*>(REX::W32::TlsGetValue(*slot));
		}

		void Clear()
		{
			using func_t = decltype(&hkMonitorStream::Clear);
			static REL::Relocation<func_t> func{ REL::ID(2257312) };
			func(this);
		}

		void Reset()
		{
			end = start;
		}

		void Resize(const std::int32_t a_newSize)
		{
			using func_t = decltype(&hkMonitorStream::Resize);
			static REL::Relocation<func_t> func{ REL::ID(2257310) };
			func(this, a_newSize);
		}

		// members
		hkPadSpu<char*> start;                       // 00
		hkPadSpu<char*> end;                         // 08
		hkPadSpu<char*> capacity;                    // 10
		hkPadSpu<char*> capacityMinus16;             // 18
		hkBool          isBufferAllocatedOnTheHeap;  // 20
	};
	static_assert(sizeof(hkMonitorStream) == 0x28);
}
