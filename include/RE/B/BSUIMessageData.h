#pragma once

#include "RE/I/IUIMessageData.h"

namespace RE
{
	class __declspec(novtable) BSUIMessageData :
		public IUIMessageData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSUIMessageData };
		static constexpr auto VTABLE{ VTABLE::BSUIMessageData };

		static void SendUIBoolMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, bool a_value)
		{
			using func_t = decltype(&BSUIMessageData::SendUIBoolMessage);
			static REL::Relocation<func_t> func{ REL::ID(1388308) };
			return func(a_menuName, a_type, a_value);
		}

		static void SendUIStringMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, const BSFixedString& a_string)
		{
			using func_t = decltype(&BSUIMessageData::SendUIStringMessage);
			static REL::Relocation<func_t> func{ REL::ID(1270833) };
			return func(a_menuName, a_type, a_string);
		}

		static void SendUIPtrMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, void* a_data)
		{
			using func_t = decltype(&BSUIMessageData::SendUIPtrMessage);
			static REL::Relocation<func_t> func{ REL::ID(1374542) };
			return func(a_menuName, a_type, a_data);
		}

		static void SendUIStringUIntMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, const BSFixedString& a_fixedString, std::uint32_t a_data)
		{
			using func_t = decltype(&BSUIMessageData::SendUIStringUIntMessage);
			static REL::Relocation<func_t> func{ REL::ID(99795) };
			return func(a_menuName, a_type, a_fixedString, a_data);
		}

		// members
		BSStringT<char>* string{ nullptr };  // 18
		BSFixedString    fixedString;        // 20
		union
		{
			std::uint32_t u;
			void*         p{ nullptr };
			float         f;
			bool          b;
		} data;  // 28
	};
	static_assert(sizeof(BSUIMessageData) == 0x30);
}
