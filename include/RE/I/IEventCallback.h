#pragma once

namespace RE
{
	namespace REFREventCallbacks
	{
		class IEventCallback :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::REFREventCallbacks__IEventCallback };
			static constexpr auto VTABLE{ VTABLE::REFREventCallbacks__IEventCallback };

			virtual ~IEventCallback();  // 00

			// add
			virtual void                 operator()() = 0;                  // 01
			virtual bool                 Save(BSStorage& a_storage);        // 02
			virtual const BSFixedString* GetType() = 0;                     // 03
			virtual bool                 Load(const BSStorage& a_storage);  // 04
		};
		static_assert(sizeof(IEventCallback) == 0x10);
	}
}
