#pragma once

namespace RE
{
	class __declspec(novtable) INIPrefSettingCollection :
		public INISettingCollection  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::INIPrefSettingCollection };
		static constexpr auto VTABLE{ VTABLE::INIPrefSettingCollection };

		[[nodiscard]] static INIPrefSettingCollection* GetSingleton()
		{
			static REL::Relocation<INIPrefSettingCollection**> singleton{ REL::ID(2703234) };
			return *singleton;
		}
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x128);
}
