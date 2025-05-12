#pragma once

namespace RE
{
	class __declspec(novtable) GameSettingCollection :
		public SettingCollectionMap<Setting>  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::GameSettingCollection };
		static constexpr auto VTABLE{ VTABLE::GameSettingCollection };

		[[nodiscard]] static void InitCollection()
		{
			using func_t = decltype(&GameSettingCollection::InitCollection);
			static REL::Relocation<func_t> func{ REL::ID(2188690) };
			return func();
		}

		[[nodiscard]] static GameSettingCollection* GetSingleton()
		{
			static REL::Relocation<GameSettingCollection**> singleton{ REL::ID(2690301) };
			return *singleton;
		}

		[[nodiscard]] Setting* GetSetting(std::string_view a_name)
		{
			auto it = settings.find(a_name);
			return it != settings.end() ? it->second : nullptr;
		}
	};
	static_assert(sizeof(GameSettingCollection) == 0x138);
}
