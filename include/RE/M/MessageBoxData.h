#pragma once

#include "RE/I/IUIMessageData.h"

namespace RE
{
	class __declspec(novtable) MessageBoxData :
		public IUIMessageData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MessageBoxData };
		static constexpr auto VTABLE{ VTABLE::MessageBoxData };

		// members
		BSStringT<char>                                headerText;      // 18
		BSStringT<char>                                bodyText;        // 28
		BSTArray<BSStringT<char>>                      buttonText;      // 38
		REX::EnumSet<WARNING_TYPES, std::uint32_t>     warningContext;  // 50
		BSTSmartPointer<IMessageBoxCallback>           callback;        // 58
		REX::EnumSet<UI_DEPTH_PRIORITY, std::uint32_t> menuDepth;       // 60
		bool                                           modal;           // 64
		bool                                           ensureUnique;    // 65
	};
	static_assert(sizeof(MessageBoxData) == 0x68);
}
