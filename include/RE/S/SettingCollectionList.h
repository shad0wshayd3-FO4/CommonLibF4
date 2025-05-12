#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) SettingCollectionList :
		public SettingCollection<T>
	{
	public:
		// members
		BSSimpleList<T*> settings;  // 118
	};

	extern template class SettingCollectionList<Setting>;
}
