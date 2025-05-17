#pragma once

#include "RE/C/ConcreteFormFactory.h"

namespace RE
{
	template <class T, ENUM_FORM_ID ID, OBJECT_TYPE TYPE, OBJECT_CATEGORY_TYPE CATEGORY>
	class __declspec(novtable) ConcreteObjectFormFactory :
		public ConcreteFormFactory<T, ID>  // 00
	{
	public:
	};
}
