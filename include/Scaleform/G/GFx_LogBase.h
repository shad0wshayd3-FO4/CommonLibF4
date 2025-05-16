#pragma once

namespace Scaleform::GFx
{
	template <class T>
	class __declspec(novtable) LogBase
	{
	public:
		virtual ~LogBase();  // 00

		// add
		virtual bool IsVerboseActionErrors();  // 01
	};
}
