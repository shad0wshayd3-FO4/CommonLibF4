#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class __declspec(novtable) FlatScreenModel :
		public BSTEventSink<UIAdvanceMenusFunctionCompleteEvent>,  // 00
		public BSTSingletonSDM<FlatScreenModel>                    // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::FlatScreenModel };
		static constexpr auto VTABLE{ VTABLE::FlatScreenModel };

		[[nodiscard]] static FlatScreenModel* GetSingleton()
		{
			static REL::Relocation<FlatScreenModel**> singleton{ REL::ID(847741) };
			return *singleton;
		}

		// members
		BSFixedString customRendererName;  // 10
		void*         model;               // 18 - TODO
	};
	static_assert(sizeof(FlatScreenModel) == 0x20);
}
