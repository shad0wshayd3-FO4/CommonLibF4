#pragma once

namespace RE
{
	class BGSObjectInstance
	{
	public:
		BGSObjectInstance(TESForm* a_object, TBO_InstanceData* a_instanceData)
		{
			ctor(a_object, a_instanceData);
		}

		// members
		TESForm*                          object{ nullptr };  // 00
		BSTSmartPointer<TBO_InstanceData> instanceData;       // 08

	private:
		BGSObjectInstance* ctor(TESForm* a_object, TBO_InstanceData* a_instanceData)
		{
			using func_t = decltype(&BGSObjectInstance::ctor);
			static REL::Relocation<func_t> func{ REL::ID(2197563) };
			return func(this, a_object, a_instanceData);
		}
	};
	static_assert(sizeof(BGSObjectInstance) == 0x10);

	template <class T>
	class BGSObjectInstanceT :
		public BGSObjectInstance
	{
	public:
		BGSObjectInstanceT(T* a_object, TBO_InstanceData* a_instanceData) :
			BGSObjectInstance(a_object, a_instanceData)
		{
		}
	};
}
