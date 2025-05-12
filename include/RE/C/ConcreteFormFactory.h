#pragma once

namespace RE
{
	template <class T, ENUM_FORM_ID ID = T::FORM_ID>
	class __declspec(novtable) ConcreteFormFactory :
		public IFormFactory  // 00
	{
	public:
		[[nodiscard]] static ConcreteFormFactory* GetFormFactory()
		{
			const auto factories = GetFormFactories();
			return static_cast<ConcreteFormFactory*>(factories[std::to_underlying(ID)]);
		}

		[[nodiscard]] T* Create() { return static_cast<T*>(DoCreate()); }

		// members
		const char* name{ nullptr };
	};
}
