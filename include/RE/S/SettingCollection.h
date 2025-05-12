#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) SettingCollection
	{
	public:
		virtual ~SettingCollection() = default;  // 00

		// add
		virtual void Add(T* a_setting) = 0;                                 // 01
		virtual void Remove(T* a_setting) = 0;                              // 02
		virtual bool WriteSetting(T& a_setting) = 0;                        // 03
		virtual bool ReadSetting(T& a_setting) = 0;                         // 04
		virtual bool Open([[maybe_unused]] bool a_write) { return false; }  // 05
		virtual bool Close() { return true; }                               // 06
		virtual bool ReadSettingsFromProfile() { return false; }            // 07
		virtual bool WriteSettings() { return handle != nullptr; }          // 08
		virtual bool ReadSettings() { return handle != nullptr; }           // 09

		// members
		char  settingFile[260];  // 008
		void* handle;            // 110
	};

	extern template class SettingCollection<Setting>;
}
