#pragma once

namespace RE
{
	class BGSStoryEventManager :
		public BSTSingletonImplicit<BGSStoryEventManager>
	{
	public:
		[[nodiscard]] static BGSStoryEventManager* GetSingleton()
		{
			static REL::Relocation<BGSStoryEventManager**> singleton{ REL::ID(2693504) };
			return *singleton;
		}

		std::uint32_t AddEvent(std::uint32_t a_index, const void* a_event)
		{
			using func_t = std::uint32_t (BGSStoryEventManager::*)(std::uint32_t, const void*);
			static REL::Relocation<func_t> func{ REL::ID(2214088) };
			return func(this, a_index, a_event);
		}

		template <class T>
		std::uint32_t AddEvent(const T& a_event)
		{
			return AddEvent(T::EVENT_INDEX(), &a_event);
		}

		// members
		BSTArray<BGSRegisteredStoryEvent>        registeredEventArray;  // 00
		BSTHashMap<std::uint32_t, std::uint32_t> registeredEventIDMap;  // 18
		BSTArray<BGSStoryEvent>                  eventArray;            // 48
		BSSpinLock                               eventArrayLock;        // 60
	};
	static_assert(sizeof(BGSStoryEventManager) == 0x68);
}
