#pragma once

namespace RE
{
	class __declspec(novtable) INISettingCollection :
		public SettingCollectionList<Setting>  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::INISettingCollection };
		static constexpr auto VTABLE{ VTABLE::INISettingCollection };

		[[nodiscard]] static INISettingCollection* GetSingleton()
		{
			static REL::Relocation<INISettingCollection**> singleton{ REL::ID(2704108) };
			return *singleton;
		}

		[[nodiscard]] Setting* GetSetting(std::string_view a_name)
		{
			for (auto& setting : settings) {
				if (setting->GetKey() == a_name) {
					return setting;
				}
			}
			return nullptr;
		}
	};
	static_assert(sizeof(INISettingCollection) == 0x128);
}
